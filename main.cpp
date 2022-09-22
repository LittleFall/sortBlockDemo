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
};

std::vector<size_t> sortBlock(Block & block) {
    auto rows = block.t[0]->len();

    std::vector<size_t> perm(rows);
    std::iota(perm.begin(), perm.end(), 0);

    for (auto col_ptr_it = block.t.rbegin(); col_ptr_it != block.t.rend(); ++col_ptr_it) {
        if (auto * col_Int = dynamic_cast<ColumnInt *>(*col_ptr_it)) {
            std::stable_sort(perm.begin(), perm.end(), Comparer<ColumnInt>{col_Int});
        } else if (auto * col_String = dynamic_cast<ColumnString *>(*col_ptr_it)) {
            std::stable_sort(perm.begin(), perm.end(), Comparer<ColumnString>{col_String});
        } else if (auto * col_Double = dynamic_cast<ColumnDouble *>(*col_ptr_it)) {
            std::stable_sort(perm.begin(), perm.end(), Comparer<ColumnDouble>{col_Double});
        }
        /*
        else if (auto * col_##TYPE = dynamic_cast<Column##TYPE *>(*col_ptr_it)) {
            std::sort(perm.begin(), perm.end(), Comparer<Column##TYPE>{col_##TYPE});
        }
        */
    }

//    std::queue<std::pair<size_t, size_t>> que;
//    que.emplace(0, rows);
//    for (auto * col_ptr : block.t) {
//
//    }


    return perm;
}


int main() {
    IColumn * c1 = new ColumnInt{{1, 2, 1}};
    IColumn * c2 = new ColumnString{{"c", "a", "b"}};
    Block block = Block{.t = {c1, c2}};

    std::vector<size_t> perm = sortBlock(block);
    assert(std::vector<size_t>({2, 0, 1}) == perm);
}
