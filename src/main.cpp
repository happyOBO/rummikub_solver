#include <iostream>

#include "Banner.h"
#include "Solver.h"
#include "TileInput.h"
#include "TileRenderer.h"
#include "TileSet.h"

namespace {

constexpr int INITIAL_HAND_SIZE = 14;

void printMenu() {
    std::cout << std::endl;
    std::cout << "1: Initialize my tiles." << std::endl;
    std::cout << "2: show my tiles." << std::endl;
    std::cout << "3: Show the tiles I can submit using only my tiles." << std::endl;
    std::cout << "4: Show the tiles I can submit using tiles on table." << std::endl;
    std::cout << "5: Add new tiles in my tiles" << std::endl;
    std::cout << "6: Show tiles on the table" << std::endl;
    std::cout << "7: Write Laying My tiles on the table" << std::endl;
    std::cout << "8: Write Laying Others' tiles on the table" << std::endl;
    std::cout << "0: Exit the program" << std::endl;
    std::cout << "Press the button to do what you want. : ";
}

}  // namespace

int main() {
    Banner::showWelcome();

    TileSet hand;
    TileSet table;

    while (true) {
        printMenu();
        int button = -1;
        std::cin >> button;

        switch (button) {
            case 1:
                std::cout << "\n You pressed the button 1." << std::endl;
                hand.clear();
                table.clear();
                TileInput::readHand(hand);
                if (hand.total() == INITIAL_HAND_SIZE) {
                    std::cout << "Done." << std::endl;
                } else {
                    Banner::showError();
                    hand.clear();
                    table.clear();
                }
                break;

            case 2:
                std::cout << "\n You pressed the button 2." << std::endl;
                TileRenderer::printTileSet(hand, /*handStyle=*/true);
                break;

            case 3:
                std::cout << "\n You pressed the button 3." << std::endl;
                Solver::printSameValueGroups(hand);
                Solver::printRuns(hand);
                break;

            case 4:
                std::cout << "\n You pressed the button 4." << std::endl;
                Solver::printSameValueGroups(hand, table);
                Solver::printRuns(hand, table);
                break;

            case 5:
                std::cout << "\n You pressed the button 5." << std::endl;
                TileInput::readHand(hand);
                break;

            case 6:
                std::cout << "\n You pressed the button 6." << std::endl;
                TileRenderer::printTileSet(table);
                break;

            case 7:
                std::cout << "\n You pressed the button 7." << std::endl;
                TileInput::readTablePlacement(table, &hand);
                break;

            case 8:
                std::cout << "\n You pressed the button 8." << std::endl;
                TileInput::readTablePlacement(table, nullptr);
                break;

            case 0:
                std::cout << "You pressed the exit button." << std::endl;
                Banner::showGameEnd();
                return 0;

            default:
                Banner::showError();
                break;
        }
    }
}
