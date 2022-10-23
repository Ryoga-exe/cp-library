#include <set>
#include <utility>
#include <vector>

/// start
/// @prefix cpRangeSet
/// @description [l, r) の区間を管理するデータ構造
/// @isFileTemplate false
struct RangeSet {
public:
    using value_type = long long;
    using range_type = std::pair<value_type, value_type>;
    using container_type = std::set<range_type>;
    using iterator = typename container_type::iterator;
    using size_type = typename container_type::size_type;

private:
    container_type m_set;

public:
    explicit RangeSet() = default;
    iterator begin() const noexcept {
        return m_set.begin();
    }
    iterator end() const noexcept {
        return m_set.end();
    }
    bool empty() const noexcept {
        return m_set.empty();
    }
    size_type size() const noexcept {
        return m_set.size();
    }
    value_type coveredLength() noexcept {
        value_type result = 0;
        for (const auto& [l, r] : m_set) {
            result += (r - l);
        }
        return result;
    }
    container_type asSet() const {
        return m_set;
    }
    std::vector<range_type> asVector() const {
        std::vector<range_type> result;
        for (const auto& range : m_set) {
            result.push_back(range);
        }
        return result;
    }
    std::pair<iterator, bool> insert(const value_type left, const value_type right) {
        // todo
    }
    void erase(const value_type left, const value_type right) {
        // todo
    }
    iterator find(const value_type left, const value_type right) const {
        // todo
    }
    iterator find(const value_type x) const {
        // todo
    }
    bool contains(const value_type left, const value_type right) const {
        // todo
    }
    bool contains(const value_type x) const {
        // todo
    }
    bool isSameSegment(const value_type left, const value_type right) const {
        // todo
    }
};
