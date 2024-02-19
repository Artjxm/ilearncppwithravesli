// #include "MonsterGenerator.h"
// #include <random>
// #include <array>
//
//
// // проще было использовать static_case<Monster::MonsterType>(...)
// Monster::MonsterType MonsterGenerator::getRandomType() {
//     switch (getRandNum(0, Monster::MAX_MONSTER_TYPES)) {
//         case 0: return Monster::ORC;
//         case 1: return Monster::OGRE;
//         case 2: return Monster::TROLL;
//         case 3: return Monster::DRAGON;
//         case 4: return Monster::GOBLIN;
//         case 5: return Monster::ZOMBIE;
//         case 6: return Monster::VAMPIRE;
//         case 7: return Monster::SKELETON;
//         default: return Monster::MAX_MONSTER_TYPES;
//     }
// }
//
// int MonsterGenerator::getRandNum(int min, int max) {
//     std::random_device rd;
//     std::mt19937 mersenne(rd());
//
//     return mersenne() % max + min;
// }
//
// Monster MonsterGenerator::generateMonster() {
//     Monster::MonsterType randMonsterType(getRandomType());
//     // статический массив для того, чтобы он инициализировался всего раз
//     static std::array s_names{
//         "Jack", "Baltazar", "Bob", "Saartr", "Morpheus", "Greg", "Michael", "Vort", "Traus"
//     };
//     std::string randName(s_names.at(getRandNum(0, s_names.size())));
//
//     return Monster(randMonsterType, randName, getRandNum(1, 100));
// }
