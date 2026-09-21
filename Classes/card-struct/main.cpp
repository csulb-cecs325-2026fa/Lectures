#include <iostream>
#include <random>
#include "Card.h" // reminder, quotation marks around files that are in this project.


/**
 * Demonstrate ABSTRACTION.
 * Abstraction: stop thinking about *primitive* details; hide them behind an abstract
 *       idea, and use that idea to solve other problems without stressing over the details.
 **/

void printCard(Card card) {
    switch (card.kind) {
        case 1:
            std::cout << "Ace";
            break;
        case 11:
            std::cout << "Jack";
            break;
        case 12:
            std::cout << "Queen";
            break;
        case 13:
            std::cout << "King";
            break;
        default:
            std::cout << card.kind;
            break;
    }

    std::cout << " of ";
    switch (card.suit) {
        case 0:
            std::cout << "Spades";
            break;
        case 1:
            std::cout << "Clubs";
            break;
        case 2:
            std::cout << "Diamonds";
            break;
        case 3:
            std::cout << "Hearts";
            break;
    }
}

int main() {
    std::random_device rd{};
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> kinds{1, 13};
    std::uniform_int_distribution<int> suits{0, 3};
    /**
     * ABSTRACTION: we want to randomly choose a card to show the user.
     * Sure, a card consists of a Suit and a Kind. And maybe those could be integers,
     * or strings, or whatever. But now we're getting bogged down in little details.
     * If this was a BIGGER program, like a gambling website with MILLIONS of lines of code,
     * these details would become overwhelming.
     * It's much much easier to think about Card as a new type of thing.
     * Define variables of type Card, and don't stress over how the card is represented.
     * Just let the Card variable do its thing.
     **/

    // First, let's create a card manually.
    Card aceOfSpades {}; // Use the default values of the struct's fields.
    printCard(aceOfSpades);
    std::cout << std::endl;

    Card queenOfHearts {-3, 99999};
    // The { } will assign a value to each of the struct's fields, in the order
    // they are declared.
    printCard(queenOfHearts);
    std::cout << std::endl;

    std::cout << "Pick a card, any card...";
    std::string temp;

    for (int i = 0; i < 10; i++) {
        // Wait for the user to press Enter.
        std::getline(std::cin, temp);

        // Generate a random suit and kind.
        int randomSuit {suits(engine)};
        int randomKind {kinds(engine)};

        // Construct a new Card variable using the given suit and kind.
        Card yourCard{randomSuit, randomKind};
        printCard(yourCard);
    }
    return 0;
}
