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

    explicit Comparer(IColumn * column) : column(static_cast<T *>(column)) {}

    inline bool operator() (size_t a, size_t b)
    {
        return column->compareAt(a, b);
    }
};

std::vector<size_t> sortBlock(Block & block) {
    auto rows = block.t[0]->len();

    std::vector<size_t> perm(rows);
    std::iota(perm.begin(), perm.end(), 0);

    using It = std::vector<size_t>::iterator;

    for (auto col_ptr_it = block.t.rbegin(); col_ptr_it != block.t.rend(); ++col_ptr_it) {
        std::sort(perm.begin(), perm.end(), Comparer<ColumnInt>(*col_ptr_it));
    }
//    auto dfs = [&](It begin, It end, size_t column_id) {
////        std::sort(begin, end, column_id);
//
//    };


    return perm;
}


int main() {
    IColumn * c1 = new ColumnInt{{1, 2, 1}};
    IColumn * c2 = new ColumnString{{"c", "a", "b"}};
    Block block = Block{.t = {c1, c2}};

    std::vector<size_t> perm = sortBlock(block);
    assert(std::vector<size_t>({2, 0, 1}) == perm);
}
