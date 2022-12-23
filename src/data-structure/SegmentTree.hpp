#include <cassert>
#include <algorithm>
#include <vector>

/// start
/// @prefix cpSegmentTree
/// @description SegmentTree : セグメント木 ; math/Monoid と一緒に使う
/// @isFileTemplate false
template <class CommutativeMonoid, class Container = std::vector<typename CommutativeMonoid::value_type>>
class SegmentTree {
public:
    using value_type = typename CommutativeMonoid::value_type;
    using const_reference = const value_type&;
    using operator_type = CommutativeMonoid;
    using container_type = Container;
    
    constexpr SegmentTree() noexcept(std::is_nothrow_default_constructible_v<Container>) = default;
    explicit constexpr SegmentTree(const size_t n) noexcept(std::is_nothrow_constructible_v<Container, size_t, const value_type&>) : m_size(n) {
        for (m_leafSize = 1; m_leafSize < n;) {
            m_leafSize <<= 1;
        }
        m_segment.assign(2 * m_leafSize, CommutativeMonoid::Identity());
    }
    constexpr SegmentTree(const container_type& v) noexcept(std::is_nothrow_constructible_v<Container, size_t, const value_type&>) : m_size(v.size()) {
        for (m_leafSize = 1; m_leafSize < m_size;) {
            m_leafSize <<= 1;
        }
        m_segment.assign(2 * m_leafSize, CommutativeMonoid::Identity());
        
        for (int i = 0; i < m_size; i++) {
            m_segment[m_leafSize + i] = v[i];
        }
        for (int i = m_leafSize - 1; i >= 1; i--) {
            m_segment[i] = CommutativeMonoid::Operation(m_segment[2 * i], m_segment[2 * i + 1]);
        }
    }
    explicit constexpr operator bool() const noexcept {
        return (m_size != 0);
    }
    constexpr bool isEmpty() const noexcept {
        return (m_size == 0);
    }
    constexpr size_t size() const noexcept {
        return m_size;
    }
    constexpr size_t leafSize() const noexcept {
        return m_leafSize;
    }
    constexpr const_reference get(const size_t p) const {
        assert(0 <= p && p < m_size);
        return m_segment[p + m_leafSize];
    }
    constexpr const_reference operator[](const size_t p) const {
        return get(p);
    }
    constexpr void set(size_t p, const value_type& x) {
        assert(0 <= p && p < m_size);
        p += m_leafSize;
        m_segment[p] = x;
        update(p);
    }
    constexpr void add(size_t p, const value_type& x) {
        assert(0 <= p && p < m_size);
        p += m_leafSize;
        m_segment[p] += x;
        update(p);
    }
    constexpr value_type prod(size_t l, size_t r) const {
        assert(0 <= l && l <= r && r <= m_size);
        auto sml = CommutativeMonoid::Identity();
		auto smr = CommutativeMonoid::Identity();
		for(l += m_leafSize, r += m_leafSize; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
                sml = CommutativeMonoid::Operation(sml, m_segment[l++]);
            }
			if (r & 1) {
                smr = CommutativeMonoid::Operation(m_segment[--r], smr);
            }
		}
		return CommutativeMonoid::Operation(sml, smr);
    }
    constexpr value_type all_prod() const {
        return m_segment[1];
    }

private:
    size_t m_size = 0;
    size_t m_leafSize = 1;
    container_type m_segment;

    constexpr void update(size_t p) {
        while (p >>= 1) {
            m_segment[p] = CommutativeMonoid::Operation(m_segment[2 * p], m_segment[2 * p + 1]);
        }
    }
};
