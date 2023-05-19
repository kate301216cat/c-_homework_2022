#include <memory>
#include <vector>
#include <iostream>

class Human;

class BankCell {
public:
    explicit BankCell(int id) : cell_id(id) {}

    void addOwner(std::shared_ptr<Human> human) {
        owners.push_back(human);
    }

    int getCellId() const {
        return cell_id;
    }

    bool isCellActive() const {
        for (const auto& owner : owners) {
            if (owner.use_count() > 1) {
                return true;
            }
        }
        return false;
    }

private:
    int cell_id;
    std::vector<std::shared_ptr<Human>> owners;
};

class Human {
public:
    explicit Human(int id) : human_id(id) {}

    void addCell(std::shared_ptr<BankCell> cell) {
        cells.push_back(cell);
        cell->addOwner(shared_from_this());
    }

    int getHumanId() const {
        return human_id;
    }

    ~Human() {
        std::cout << "Human with id: " << human_id << " has died." << std::endl;
        for (auto& cell : cells) {
            if (!cell->isCellActive()) {
                std::cout << "BankCell with id: " << cell->getCellId() << " is closed." << std::endl;
            }
        }
    }

private:
    int human_id;
    std::vector<std::shared_ptr<BankCell>> cells;
};

int main() {
    auto cell1 = std::make_shared<BankCell>(1);

    {
        auto human1 = std::make_shared<Human>(1);
        auto human2 = std::make_shared<Human>(2);
        human1->addCell(cell1);
        human2->addCell(cell1);
    } // Когда оба человека умирают, банковская ячейка закрывается

    return 0;
}