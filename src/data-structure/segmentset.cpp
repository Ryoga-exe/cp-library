#include "base.hpp"

// [l, r] の区間を管理
class SegmentSet : public std::map<signed, signed> {
public:
    // doMergeAdjacentSegment : [l, c] と [c+1, r] をマージするか
    SegmentSet(const bool doMergeAdjacentSegment)
        : m_doMergeAdjacentSegment(doMergeAdjacentSegment) {}
    
    auto get(signed p) const {
        auto it = upper_bound(p);
        if (it == begin() || (--it)->second < p) {
            return end();
        }
        return it;
    }

    bool contains(signed p) const {
        auto it = get(p);
        return it != end();
    }

    bool contains(signed l, signed r) const {
        return contains(l) && contains(r) && same(l, r);
    }

    void insert(signed l, signed r) {
        auto it_left = upper_bound(l), it_right = upper_bound(r + m_doMergeAdjacentSegment);
        if (it_left != begin()) {
            if ((--it_left)->second < l - m_doMergeAdjacentSegment) {
                ++it_left;
            }
        }
        if (it_left != it_right) {
            l = std::min(l, it_left->first);
            r = std::max(r, std::prev(it_right)->second);
            erase(it_left, it_right);
        }
        (*this)[l] = r;
    }

    void remove(signed l, signed r) {
        auto it_left = upper_bound(l), it_right = upper_bound(r);
        if (it_left != begin()) {
            if ((--it_left)->second < l) {
                ++it_left;
            }
        }
        if (it_left == it_right) {
            return;
        }
        int tl = std::min(l, it_left->first), tr = std::max(r, std::prev(it_right)->second);
        erase(it_left, it_right);
        if (tl < l) {
            (*this)[tl] = l - 1;
        }
        if (r < tr) {
            (*this)[r + 1] = tr;
        }
    }

    bool same(signed p, signed q) const {
        const auto&& it = get(p);
        return it != end() && it->first <= q && q <= it->second;
    }
private:
    bool m_doMergeAdjacentSegment;
};
