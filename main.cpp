#include <queue>
#include <iostream>
#include <numeric>
#include <utility>


struct IColumn {
    virtual int compareAt(size_t a, size_t b) = 0;
    virtual size_t len() = 0;
};

struct ColumnInt final : IColumn{
    explicit ColumnInt(std::vector<int> &&t) : t(t) {};

    int compareAt(size_t a, size_t b) override {
        return t[a] < t[b] ? -1 : t[a] == t[b] ? 0 : 1;
    }

    size_t len() override {
        return t.size();
    }

    std::vector<int> t;
};

struct ColumnString final : IColumn{
    explicit ColumnString(std::vector<std::string> &&t) : t(t) {};

    int compareAt(size_t a, size_t b) override {
        return t[a] < t[b] ? -1 : t[a] == t[b] ? 0 : 1;
    }

    size_t len() override {
        return t.size();
    }

    std::vector<std::string> t;
};

struct ColumnDouble final : IColumn{
    int compareAt(size_t a, size_t b) override {
        return t[a] < t[b] ? -1 : t[a] == t[b] ? 0 : 1;
    }
    size_t len() override {
        return t.size();
    }
    std::vector<double> t;
};

struct Block {
    std::vector<IColumn *> t;
};

template <typename T>
struct Comparer {
    T * column;

    inline bool operator() (size_t a, size_t b)
    {
        return column->compareAt(a, b) < 0;
    }
    inline bool equal(size_t a, size_t b) const
    {
        return column->compareAt(a, b) == 0;
    }
};


template <typename T>
auto sortByColumn(std::vector<size_t> & perm, const std::vector<std::pair<int, int>> & queue, const Comparer<T> & comparer) {
    for (auto & [begin, end] : queue) {
        std::sort(perm.begin() + begin, perm.begin() + end, comparer);
    }

    std::vector<std::pair<int, int>> nq;
    for (auto & [begin, end] : queue) {
        // assert(end>begin+1)
        auto nb = -1;
        for (auto id = begin; id < end - 1; ++id) {
            if (comparer.equal(perm[id], perm[id+1])) {
                if (nb == -1) {
                    nb = id;
                }
            } else {
                if (nb != -1) {
                    nq.emplace_back(nb, id+1);
                    nb = -1;
                }
            }
        }
    }
    return nq;
}

std::vector<size_t> sortBlock(Block & block) {
    auto rows = block.t[0]->len();

    std::vector<size_t> perm(rows);
    std::iota(perm.begin(), perm.end(), 0);

    std::vector<std::pair<int, int>> queue;
    queue.emplace_back(0, rows);
    for (auto * col_ptr : block.t) {
        if (auto * col_Int = dynamic_cast<ColumnInt *>(col_ptr)) {
            queue = sortByColumn(perm, queue, Comparer<ColumnInt>{col_Int});
        } else if (auto * col_String = dynamic_cast<ColumnString *>(col_ptr)) {
            queue = sortByColumn(perm, queue, Comparer<ColumnString>{col_String});
        } else if (auto * col_Double = dynamic_cast<ColumnDouble *>(col_ptr)) {
            queue = sortByColumn(perm, queue, Comparer<ColumnDouble>{col_Double});
        }  // ... xmacro
    }

    return perm;
}


int main() {
    IColumn * c1 = new ColumnInt{{1, 2, 1}};
    IColumn * c2 = new ColumnString{{"c", "a", "b"}};
    Block block = Block{.t = {c1, c2}};

    std::vector<size_t> perm = sortBlock(block);
    assert(std::vector<size_t>({2, 0, 1}) == perm);
}
