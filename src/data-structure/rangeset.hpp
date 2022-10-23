#include <set>
#include <utility>
#include <iterator>
#include <vector>
#include <cassert>
#include <algorithm>

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
        assert(left <= right);
        if (left == right) {
            return { m_set.end(), false };
        }
        auto itr = m_set.lower_bound({ left, right });
        if (itr != m_set.end() && itr->first == left) {
            return { itr, false };
        }
        if (itr != m_set.begin()) {
            if (const auto prev_itr = std::prev(itr); prev_itr->first != left && right <= prev_itr->second) {
                return { std::prev(itr), false };
            }
        }
        itr = m_set.emplace_hint(itr, left, right);
        while (itr != std::prev(m_set.end()) && std::next(itr)->first <= itr->second) {
            if (std::next(itr)->second <= itr->second) {
                m_set.erase(std::next(itr));
            }
            else {
                itr = m_set.emplace_hint(std::next(itr), itr->first, std::next(itr)->second);
                m_set.erase(std::prev(itr));
                m_set.erase(std::next(itr));
            }
        }
        while (itr != m_set.begin() && itr->first <= std::prev(itr)->second) {
            if (itr->first == std::prev(itr)->first) {
                m_set.erase(std::prev(itr));
            }
            else {
                itr = m_set.emplace_hint(itr, std::prev(itr)->first, itr->second);
                m_set.erase(std::prev(itr));
                m_set.erase(std::next(itr));
            }
        }
        return { itr, true };
    }
    void erase(const value_type left, const value_type right) {
        assert(left <= right);
        if (left == right) {
            return;
        }
        auto itr_l = m_set.upper_bound({ left, left });
        auto itr_r = m_set.upper_bound({ right, right });
        if (itr_l != m_set.begin()) {
            if (std::prev(itr_l)->second >= left) {
                itr_l--;
            }
        }
        if (itr_l == itr_r) {
            return;
        }
        auto tl = std::min(left, itr_l->first);
        auto tr = std::max(right, std::prev(itr_r)->second);
        m_set.erase(itr_l, itr_r);
        if (tl < left) {
            m_set.insert({ tl, left });
        }
        if (right < tr) {
            m_set.insert({ right, tr });
        }
    }
    iterator find(const value_type x) const {
        auto itr = m_set.lower_bound({ x, x });
        if (itr == begin() || (--itr)->second < x) {
            return m_set.end();
        }
        return itr;
    }
    iterator find(const value_type left, const value_type right) const {
        assert(left <= right);
        auto itr_l = find(left);
        auto itr_r = find(right);
        if (itr_l == m_set.end() || itr_r == m_set.end()) {
            return m_set.end();
        }
        if (itr_l == itr_r) {
            return itr_l;
        }
        else {
            return m_set.end();
        }
    }
    bool contains(const value_type left, const value_type right) const {
        assert(left <= right);
        return find(left, right) != m_set.end();
    }
    bool contains(const value_type x) const {
        return find(x) != m_set.end();
    }
    bool isSameSegment(const value_type x, const value_type y) const {
        auto itr_x = find(x);
        auto itr_y = find(y);
        return itr_x != end() && itr_x == itr_y;
    }
};
