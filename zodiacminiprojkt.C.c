#include <stdio.h>
#include<string.h>

// Function prototypes
void displayWesternZodiac(int day, int month);
void displayVedicZodiac(int day, int month, int year);
void displayChineseZodiac(int year);
void displayEgyptianZodiac(int day, int month);
void displayCelticZodiac(int day, int month);

int main() {
    int choice;
    int day, month, year;

    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Zodiac Sign Calculator\n");
        printf("1. Western Zodiac\n");
        printf("2. Indian Zodiac (Vedic)\n");
        printf("3. Chinese Zodiac\n");
        printf("4. Egyptian Zodiac\n");
        printf("5. Celtic Zodiac\n");
        printf("6. Exit\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 6) {
            printf("Thanks for using 🙏\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter your birth date (day month): ");
                scanf("%d %d", &day, &month);
                displayWesternZodiac(day, month);
                break;
            case 2:
                printf("Enter your birth date (day month year): ");
                scanf("%d %d %d", &day, &month, &year);
                displayVedicZodiac(day, month, year);
                break;
            case 3:
                printf("Enter your birth year: ");
                scanf("%d", &year);
                displayChineseZodiac(year);
                break;
            case 4:
                printf("Enter your birth day: ");
                scanf("%d", &day);
                printf("Enter your birth month: ");
                scanf("%d", &month);
                displayEgyptianZodiac(day, month);
                break;
            case 5:
                printf("Enter your birth day (1-31): ");
                scanf("%d", &day);
                printf("Enter your birth month (1-12): ");
                scanf("%d", &month);
                displayCelticZodiac(day, month);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayWesternZodiac(int day, int month) {
    const char *signs[] = {
        "Capricorn ♑︎", "Aquarius ♒︎", "Pisces ♓︎", "Aries ♈︎", "Taurus ♉︎", 
        "Gemini ♊︎", "Cancer ♋︎", "Leo ♌︎", "Virgo ♍︎", "Libra ♎︎", 
        "Scorpio ♏︎",  "Sagittarius ♐︎"
    };

    const char *traits[] = {
        "Responsible, disciplined, self-control, good managers.",
        "Progressive, original, independent, humanitarian.",
        "Compassionate, artistic, intuitive, gentle, wise, musical.",
        "Courageous, determined, confident, enthusiastic, optimistic, honest, passionate.",
        "Reliable, patient, practical, devoted, responsible, stable.",
        "Gentle, affectionate, curious, adaptable, ability to learn quickly and exchange ideas.",
        "Tenacious, highly imaginative, loyal, emotional, sympathetic, persuasive.",
        "Creative, passionate, generous, warm-hearted, cheerful, humorous.",
        "Loyal, analytical, kind, hardworking, practical.",
        "Cooperative, diplomatic, gracious, fair-minded, social.",
        "Resourceful, brave, passionate, stubborn, a true friend.",
        "Generous, idealistic, great sense of humor."
    };

    const char *elements[] = {
        "Earth 🜃", "Air 🜁", "Water 🜄", "Fire 🜂", "Earth 🜃", 
        "Air 🜁", "Water 🜄", "Fire 🜂", "Earth 🜃", "Air 🜁", 
        "Water 🜄", "Fire 🜂"
    };

    const char *qualities[] = {
        "Cardinal ⟑", "Fixed 🝕", "Mutable 🜳", "Cardinal ⟑", "Fixed 🝕", 
        "Mutable 🜳", "Cardinal ⟑", "Fixed 🝕", "Mutable 🜳", "Cardinal ⟑", 
        "Fixed 🝕", "Mutable 🜳"
    };

    const char *polarities[] = {
        "Negative (-) ", "Positive (+) ", "Negative (-)", "Positive (+)", "Negative (-)", 
        "Positive (+)", "Negative (-)", "Positive (+)", "Negative (-)", "Positive (+)", 
        "Negative (-)", "Positive (+)"
    };

    const char *rulingPlanets[] = {
        "Saturn ♄", "Uranus ♅", "Neptune ♆", "Mars ♂", "Venus ♀", 
        "Mercury ☿", "Moon ☾", "Sun ☉", "Mercury ☿", "Venus", 
        "Pluto ♇", "Mars ♂", "Jupiter ♃"
    };

    const char *rulingHouses[] = {
        "10th House",  "11th House", "12th House", "1st House", "2nd House", 
        "3rd House", "4th House", "5th House", "6th House", "7th House", 
        "8th House", "9th House"
    };

    const char *spiritColors[] = {
        "Dark Blue 💙", "Sky Blue 💙", "Sea Green 💚", "Red ❤️", "Pink 🩷", 
        "Yellow 💛", "Violet 💜", "Gold ⭐", "Silver 🩶", "Blue 💙", 
        "Black 🖤", "Light Blue 💙"
    };

    const char *luckyGems[] = {
        "Lapis Lazuli", "Amethyst", "Moonstone", "Diamond", "Emerald", 
        "Tiger's Eye, Emerald", "Ruby, Pearl", "Carnelian", "Peridot", "Sapphire", 
        "Topaz, Opal", "Topaz"
    };

    const char *flowers[] = {
        "Pansy", "Orchid", "Water Lily ", "Thistle & Honeysuckle", "Rose, Poppy & Foxglove", 
        "Lavender & Lily of the Valley", "Orchid & White Rose", "Sunflower & Marigold", 
        "Sunflower & Marigold", "Rose", "Hibiscus & Geraniums", "Carnations & Crocuses"
    };

    const char *topLoveMatches[] = {
        "Virgo ♍︎", "Sagittarius ♐︎", "Virgo ♍︎", "Sagittarius ♐︎", "Cancer ♋︎ & Virgo ♍︎", 
        "Aries ♈︎ & Leo", "Taurus ♉︎ & Pisces ♓︎", "Libra", "Cancer ♋︎", "Gemini ♊︎", 
        "Cancer ♋︎", "Aries ♈︎"
    };

    // Determine the zodiac sign based on the date
    int index;
    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) index = 1; // Aquarius
    else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) index = 2; // Pisces
    else if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) index = 3; // Aries
    else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) index = 4; // Taurus
    else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) index = 5; // Gemini
    else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) index = 6; // Cancer
    else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) index = 7; // Leo
    else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) index = 8; // Virgo
    else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) index = 9; // Libra
    else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) index = 10; // Scorpio
    else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) index = 11; // Sagittarius
    else index = 0; // Capricorn

    printf("Your Western Zodiac sign is : %s\n", signs[index]);
    printf("Personality Traits : %s\n", traits[index]);
    printf("Element : %s\n", elements[index]);
    printf("Quality : %s\n", qualities[index]);
    printf("Polarity : %s\n", polarities[index]);
    printf("Ruling Planet : %s\n", rulingPlanets[index]);
    printf("Ruling House : %s\n", rulingHouses[index]);
    printf("Spirit Color : %s\n", spiritColors[index]);
    printf("Lucky Gem : %s\n", luckyGems[index]);
    printf("Flower : %s\n", flowers[index]);
    printf("Top Love Matches : %s\n", topLoveMatches[index]);
}

void displayVedicZodiac(int day, int month, int year) {
    const char *signs[] = {
        "Capricorn (Makara) ♑︎", "Aquarius (Kumbha) ♒︎", "Pisces (Meena)  ♓︎",
        "Aries (Mesha) ♈︎", "Taurus (Vrishabha) ♉︎", "Gemini (Mithuna) ♊︎",
        "Cancer (Karka) ♋︎", "Leo (Simha) ♌︎", "Virgo (Kanya) ♍︎",
        "Libra (Tula) ♎︎", "Scorpio (Vrishchika) ♏︎", "Sagittarius (Dhanu) ♐︎"
    };

    const char *traits[] = {
        "Disciplined, responsible, and practical.",
        "Innovative, humanitarian, and independent.",
        "Compassionate, artistic, and intuitive.",
        "Courageous, enthusiastic, and energetic.",
        "Reliable, patient, and practical.",
        "Adaptable, communicative, and curious.",
        "Nurturing, emotional, and protective.",
        "Confident, generous, and charismatic.",
        "Analytical, meticulous, and practical.",
        "Diplomatic, fair-minded, and social.",
        "Passionate, resourceful, and determined.",
        "Optimistic, adventurous, and philosophical."
    };

    int signIndex;

    if ((month == 1 && day >= 14) || (month == 2 && day <= 12)) {
        signIndex = 0; // Capricorn
    } else if ((month == 2 && day >= 13) || (month == 3 && day <= 14)) {
        signIndex = 1; // Aquarius
    } else if ((month == 3 && day >= 15) || (month == 4 && day <= 13)) {
        signIndex = 2; // Pisces
    } else if ((month == 4 && day >= 14) || (month == 5 && day <= 14)) {
        signIndex = 3; // Aries
    } else if ((month == 5 && day >= 15) || (month == 6 && day <= 14)) {
        signIndex = 4; // Taurus
    } else if ((month == 6 && day >= 15) || (month == 7 && day <= 15)) {
        signIndex = 5; // Gemini
    } else if ((month == 7 && day >= 16) || (month == 8 && day <= 15)) {
        signIndex = 6; // Cancer
    } else if ((month == 8 && day >= 16) || (month == 9 && day <= 15)) {
        signIndex = 7; // Leo
    } else if ((month == 9 && day >= 16) || (month == 10 && day <= 15)) {
        signIndex = 8; // Virgo
    } else if ((month == 10 && day >= 16) || (month == 11 && day <= 14)) {
        signIndex = 9; // Libra
    } else if ((month == 11 && day >= 15) || (month == 12 && day <= 14)) {
        signIndex = 10; // Scorpio
    } else {
        signIndex = 11; // Sagittarius
    }

    printf("Your Vedic Zodiac sign is: %s\n", signs[signIndex]);
    printf("Personality Traits: %s\n", traits[signIndex]);
}

void displayChineseZodiac(int year) {
    const char *signs[] = {
        "Rat 🐀", "Ox 🐂", "Tiger 🐅", "Rabbit 🐇", "Dragon 🐉", 
        "Snake 🐍", "Horse 🐎", "Goat 🐐", "Monkey 🐒", "Rooster 🐓", 
        "Dog 🐕", "Pig 🐖"
    };

    const char *traits[] = {
        "Quick-witted , charming, and sociable.",
        "Diligent, dependable, and strong.",
        "Brave, competitive, and unpredictable.",
        "Gentle, quiet, and compassionate.",
        "Confident, intelligent, and enthusiastic.",
        "Wise, discreet, and intuitive.",
        "Energetic, independent, and free-spirited.",
        "Creative, gentle, and compassionate.",
        "Clever, curious, and mischievous.",
        "Observant, hardworking, and courageous.",
        "Loyal, honest, and friendly.",
        "Generous, compassionate, and easy-going."
    };

    const char *elements[] = {
        "Water 💧", "Earth 🪨", "Wood 🪵", "Wood 🪵", "Earth 🪨", 
        "Fire 🔥", "Fire 🔥", "Earth 🪨", "Metal 🪙", "Metal 🪙", 
        "Earth 🪨", "Water 💧"
    };

    const char *polarities[] = {
        "Yin ⚫ ", "Yin ⚫ ", "Yang ⚪", "Yin ⚫ ", "Yang ⚪",   
        "Yin ⚫ ", "Yang ⚪", "Yin ⚫ ", "Yang ⚪", "Yin ⚫ ", 
        "Yang ⚪", "Yin ⚫ "
    };

    const char *rulingPlanets[] = {
        "Mercury ☿", "Saturn ♄", "Jupiter ♃", "Venus ♀", "Mars ♂", 
        "Saturn ♄", "Sun ☉", "Moon ☾", "Mercury ☿", "Venus ♀", 
        "Saturn ♄", "Jupiter ♃"
    };

    const char *spiritColors[] = {
        "Blue 💙", "Yellow ⭐", "Green 💚", "Pink 🩷", "Red ❤️", 
        "Black 🖤", "Gold 💛", "White 🤍", "Silver 🩶", "Orange 🧡", 
        "Brown 🤎", "Purple 💜"
    };

    const char *luckyGems[] = {
        "Garnet", "Aquamarine", "Sapphire", "Jade", "Amethyst", 
        "Topaz", "Ruby", "Emerald", "Peridot", "Diamond", 
        "Opal", "Aquamarine"
    };

    const char *flowers[] = {
        "Lily", "Tulip", "Plum Blossom", "Jasmine", "Peony", 
        "Orchid", "Marigold", "Carnation", "Chrysanthemum", "Gladiolus", 
        "Rose", "Lotus"
    };

    const char *bestMatches[] = {
        "Ox 🐂, Dragon 🐉, Monkey 🐒", "Rat 🐀, Snake 🐍, Rooster 🐓", "Horse 🐎, Dog 🐕, Pig 🐖", 
        "Goat 🐐, Dog 🐕, Pig 🐖", "Rat 🐀, Monkey 🐒, Rooster 🐓", "Ox 🐂, Rooster 🐓, Dragon 🐉", 
        "Tiger 🐅, Goat 🐐, Dog 🐕", "Rabbit 🐇, Horse 🐎, Pig 🐖", "Rat 🐀, Dragon 🐉, Snake 🐍", 
        "Ox 🐂, Snake 🐍, Dragon 🐉", "Tiger 🐅, Rabbit 🐇, Horse 🐎", "Rabbit 🐇, Goat 🐐, Tiger 🐅"
    };

    const char *challengingMatches[] = {
        "Horse 🐎, Rabbit 🐇", "Goat 🐐, Tiger 🐅", "Ox 🐂, Monkey 🐒", 
        "Rooster 🐓, Rat 🐀", "Dog 🐕, Rabbit 🐇", "Pig 🐖, Tiger 🐅", 
        "Rat 🐀, Ox 🐂", "Ox 🐂, Tiger 🐅", "Tiger 🐅, Pig 🐖", 
        "Rabbit 🐇, Dog 🐕", "Dragon 🐉, Rooster 🐓", "Monkey 🐒, Snake 🐍"
    };

    int index = (year - 4) % 12;  // Chinese Zodiac starts from 4 AD
    printf("Your Chinese Zodiac sign is: %s\n", signs[index]);
    printf("Personality Traits: %s\n", traits[index]);
    printf("Element: %s\n", elements[index]);
    printf("Polarity: %s\n", polarities[index]);
    printf("Ruling Planet: %s\n", rulingPlanets[index]);
    printf("Spirit Color: %s\n", spiritColors[index]);
    printf("Lucky Gem: %s\n", luckyGems[index]);
    printf("Flower: %s\n", flowers[index]);
    printf("Best Matches: %s\n", bestMatches[index]);
    printf("Challenging Matches: %s\n", challengingMatches[index]);
}



void displayEgyptianZodiac(int day, int month) {
    // Arrays to hold the zodiac sign information
    const char *zodiacNames[] = {
        "Amun 𓀃", "Ra 𓀎", "Osiris 𓀷", "Isis 𓁖", "Horus 𓁭", "Seth 𓁯", 
        "Anubis 𓁢", "Thoth 𓁟", "Sekhmet 𓁈", "Bastet 𓁛", "Mut 𓁖", "Geb 𓅋"
    };

    const char *personalityTraits[] = {
        "Mysterious, powerful, and protective.",
        "Energetic, creative, and optimistic.",
        "Wise, nurturing, and protective.",
        "Compassionate, loving, and intuitive.",
        "Visionary, ambitious, and strong-willed.",
        "Independent, assertive, and dynamic.",
        "Mysterious, protective, and loyal.",
        "Intelligent, wise, and communicative.",
        "Strong, fierce, and protective.",
        "Nurturing, playful, and loving.",
        "Mysterious, intuitive, and spiritual.",
        "Grounded, nurturing, and stable."
    };

    const char *elements[] = {
        "Fire 🜂", "Fire 🜂", "Earth 🜃", "Water 🜄", "Air 🜁", "Fire 🜂", 
        "Earth 🜃", "Air 🜁", "Fire 🜂", "Fire 🜂", "Water 🜄", "Earth 🜃"
    };

    const char *qualities[] = {
        "Leader", "Creator", "Rebirth", "Healer", "Courageous", "Warrior", 
        "Transformative", "Knowledgeable", "Fierce", "Protector", "Nurturer", "Grounded"
    };

    const char *polarities[] = {
        "Positive (+)", "Positive (+)", "Positive (+)", "Negative (-)", "Positive", "Negative (-)", 
        "Negative (-)", "Positive (+)", "Positive (+)", "Positive (+)", "Negative (-)", "Negative (-)"
    };

    const char *rulingPlanets[] = {
        "Sun ☉", "Sun ☉", "Saturn ♄" , "Moon ☾" , "Sun ☉"  , "Mars ♂" , 
        "Pluto ♇", "Mercury ☿", "Mars ♂", "Venus ♀", "Moon ☾", "Venus ♀"
    };

    const char *spiritColors[] = {
        "Gold ⭐", "Yellow 💛", "Green 💚" , "White 🤍", "Blue 💙", "Black 🖤", 
        "Black 🖤", "Yellow 💛", "Red ❤️", "Red ❤️" , "Silver 🩶", "Brown 🤎"
    };

    const char *luckyGems[] = {
        "Sunstone", "Amber", "Onyx", "Moonstone", "Sapphire", "Garnet", 
        "Obsidian", "Emerald", "Carnelian", "Ruby", "Pearl", "Turquoise"
    };

    const char *flowers[] = {
        "Sunflower", "Marigold", "Lily", "Jasmine", "Rose", "Cactus Flower", 
        "Gladiolus", "Daffodil", "Hibiscus", "Carnation", "Lotus", "Dandelion"
    };

    const char *bestMatches[][3] = {
        {"Ra 𓀎", "Mut 𓁯", "Horus 𓁭"}, {"Amun 𓀃", "Sekhmet 𓁈", "Thoth 𓁟"}, {"Isis 𓁖", "Horus 𓁭", "Anubis 𓁢"},
        {"Osiris 𓀷", "Horus 𓁭", "Thoth"}, {"Amun 𓀃", "Isis 𓁖", "Ra"}, {"Sekhmet 𓁈", "Bastet 𓁟", "Anubis 𓁢"},
        {"Osiris 𓀷", "Thoth 𓁟", "Mut"}, {"Isis 𓁖", "Anubis 𓁢", "Ra 𓀎"}, {"Ra 𓀎", "Seth 𓁯", "Horus 𓁭"},
        {"Seth 𓅋", "Mut 𓁖", "Thoth 𓁟"}, {"Amun 𓀃", "Anubis 𓁢", "Osiris 𓀷"}, {"Thoth 𓁖", "Isis 𓁖", "Bastet"}
    };

    const char *challengingMatches[][3] = {
        {"Seth 𓁯", "Anubis 𓁢", "Horus 𓁭"}, {"Geb 𓁛", "Bastet 𓁖", "Seth 𓁯"}, {"Seth 𓁛", "Sekhmet", "Ra 𓀎"},
        {"Seth 𓁯", "Sekhmet 𓁈", "Ra 𓀎"}, {"Seth 𓁟", "Mut 𓅋", "Anubis"}, {"Osiris 𓀷", "Ra 𓁛", "Horus 𓁭"},
        {"Sekhmet 𓁖", "Amun", "Ra 𓀎"}, {"Seth 𓁯", "Horus 𓁭", "Ra 𓀎"}, {"Anubis 𓁢", "Mut 𓁛", "Ra"},
        {"Ra 𓀎", "Horus 𓁭", "Seth 𓅋"}, {"Seth 𓅋", "Sekhmet 𓁛", "Ra 𓀎"}, {"Ra 𓀎", "Sekhmet 𓁈", "Horus 𓁭"}
    };

    int index = -1;

    if ((month == 1 && day >= 1 && day <= 15) || (month == 12 && day >= 16 && day <= 31)) {
        index = 0;
    } else if ((month == 1 && day >= 16) || (month == 2 && day <= 15)) {
        index = 1;
    } else if ((month == 2 && day >= 16) || (month == 3 && day <= 15)) {
        index = 2;
    } else if ((month == 3 && day >= 16) || (month == 4 && day <= 15)) {
        index = 3;
    } else if ((month == 4 && day >= 16) || (month == 5 && day <= 15)) {
        index = 4;
    } else if ((month == 5 && day >= 16) || (month == 6 && day <= 15)) {
        index = 5;
    } else if ((month == 6 && day >= 16) || (month == 7 && day <= 15)) {
        index = 6;
    } else if ((month == 7 && day >= 16) || (month == 8 && day <= 15)) {
        index = 7;
    } else if ((month == 8 && day >= 16) || (month == 9 && day <= 15)) {
        index = 8;
    } else if ((month == 9 && day >= 16) || (month == 10 && day <= 15)) {
        index = 9;
    } else if ((month == 10 && day >= 16) || (month == 11 && day <= 15)) {
        index = 10;
    } else if ((month == 11 && day >= 16) || (month == 12 && day <= 15)) {
        index = 11;
    }

    if (index != -1) {
        printf("Your Egyptian Zodiac sign is: %s\n", zodiacNames[index]);
        printf("Personality Traits: %s\n", personalityTraits[index]);
        printf("Element: %s\n", elements[index]);
        printf("Quality: %s\n", qualities[index]);
        printf("Polarity: %s\n", polarities[index]);
        printf("Ruling Planet: %s\n", rulingPlanets[index]);
        printf("Spirit Color: %s\n", spiritColors[index]);
        printf("Lucky Gem: %s\n", luckyGems[index]);
        printf("Flower: %s\n", flowers[index]);
        printf("Best Matches: %s, %s, %s\n", bestMatches[index][0], bestMatches[index][1], bestMatches[index][2]);
        printf("Challenging Matches: %s, %s, %s\n", challengingMatches[index][0], challengingMatches[index][1], challengingMatches[index][2]);
    } else {
        printf("Invalid date.\n");
    }
}




void displayCelticZodiac(int day, int month) {
    const char *signs[] = {
        "Willow", "Ash", "Oak", "Hawthorn", "Vine", 
        "Reed", "Elder", "Rowan", "Birch", "Yew"
    };

    const char *traits[] = {
        "Intuitive, adaptable, and sensitive.",
        "Strong, wise, and resilient.",
        "Strong, dependable, and wise.",
        "Creative, imaginative, and sensitive.",
        "Passionate, artistic, and expressive.",
        "Flexible, adaptable, and resourceful.",
        "Intuitive, wise, and protective.",
        "Brave, adventurous, and confident.",
        "New beginnings, growth, and renewal.",
        "Mysterious, transformative, and deep."
    };

    const char *elements[] = {
        "Water 🜄", "Water 🜄", "Earth 🜃", "Fire 🜂", "Earth 🜃", 
        "Water 🜄", "Water 🜄", "Fire 🜂", "Air 🜁", "Earth 🜃"
    };

    const char *qualities[] = {
        "Intuitive", "Visionary", "Stabilizer", "Enchanter", "Harmonizer", 
        "Secretive", "Wise", "Thinker", "Visionary", "Transformative"
    };

    const char *polarities[] = {
        "Negative (-)", "Positive (+)", "Positive (+)", "Positive (+)", "Negative (-)", 
        "Negative (-)", "Negative (-)", "Negative (-)", "Positive (+)", "Negative (-)"
    };

    const char *rulingPlanets[] = {
        "Moon ☾", "Neptune ♆", "Jupiter ♃", "Mars ♂", "Venus ♀", 
        "Pluto ♇", "Saturn ♄", "Uranus ♅", "Sun ☉", "Pluto ♇"
    };

    const char *spiritColors[] = {
        "Silver 🩶", "Blue 💙", "Gold ⭐", "Pink 🩷", "Purple 💜", 
        "Black 🖤", "White 🤍", "Green", "White 🤍", "Black 🖤"
    };

    const char *luckyGems[] = {
        "Moonstone", "Amethyst", "Sapphire", "Topaz", "Emerald", 
        "Obsidian", "Jet", "Garnet", "Quartz", "Onyx"
    };

    const char *flowers[] = {
        "Willow Flower", "Water Lily", "Oak Blossom", "Hawthorn Blossom", "Vine Flower", 
        "Reed Grass", "Elder Flower", "Snowdrop", "Dandelion", "Yew Blossom"
    };

    const char *bestMatches[] = {
        "Ash🌲 , Reed 🌳, Rowan 𖠰", "Willow 🌲, Birch 𖠰, Rowan 🌳", "Hawthorn 🌲, Birch 𖠰, Reed 🌳", 
        "Oak 𖠰, Vine 🌳, Rowan 🌲", "Ash 🌲, Elder 𖠰, Hawthorn 🌲", 
        "Willow 🌳, Oak 🌲, Birch 𖠰", "Vine 🌳, Yew 🌲, Rowan 𖠰", "Ash 🌳, Hawthorn 🌲, Elder 𖠰", 
        "Ash 🌲, Oak 🌳, Reed 𖠰", "Elder 🌳, Reed 🌲, Rowan 𖠰"
    };

    const char *challengingMatches[] = {
        "Oak 𖠰, Elder 🌳", "Vine 🌳, Yew 🌲", "Rowan 𖠰, Elder 🌳", 
        "Yew 🌲, Reed 𖠰", "", "Willow 🌲, Rowan 𖠰", 
        "Oak 🌲, Willow 𖠰", "Oak 𖠰, Vine 🌳", "Willow 🌲, Yew 🌳", 
        "Hawthorn 🌲, Birch 𖠰"
    };

    int signIndex = -1;

    // Determine the zodiac sign based on the date
    if ((month == 3 && day >= 1 && day <= 20) || (month == 2 && day >= 21)) {
        signIndex = 0; // Willow
    } else if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
        signIndex = 1; // Ash
    } else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        signIndex = 2; // Oak
    } else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        signIndex = 3; // Hawthorn
    } else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        signIndex = 2; // Oak
    } else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
        signIndex = 4; // Vine
    } else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        signIndex = 5; // Reed
    } else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        signIndex = 6; // Elder
    } else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        signIndex = 7; // Rowan
    } else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        signIndex = 8; // Birch
    } else if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
        signIndex = 9; // Yew
    } else {
        printf("Invalid date.\n");
        return;
    }

    // Output the zodiac sign and its attributes
    printf("Your Celtic Zodiac sign is: %s\n", signs[signIndex]);
    printf("Personality Traits: %s\n", traits[signIndex]);
    printf("Element: %s\n", elements[signIndex]);
    printf("Quality: %s\n", qualities[signIndex]);
    printf("Polarity: %s\n", polarities[signIndex]);
    printf("Ruling Planet: %s\n", rulingPlanets[signIndex]);
    printf("Spirit Color: %s\n", spiritColors[signIndex]);
    printf("Lucky Gem: %s\n", luckyGems[signIndex]);
    printf("Flower: %s\n", flowers[signIndex]);
    printf("Best Matches: %s\n", bestMatches[signIndex]);
    printf("Challenging Matches: %s\n", challengingMatches[signIndex]);
}

