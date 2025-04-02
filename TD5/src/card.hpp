#pragma once 

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash () const{
        return 52 * static_cast<int>(kind) + static_cast<int>(value);
    }
};


bool operator==(Card const& a, Card const& b);
std::vector<Card> get_cards(size_t const size);
std::string card_name(Card const& card);

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

