    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#pragma once

#include <string>

//ОСНОВНЫЕ
const int CHECKER_SIZE = 64; //Размер одной шашки
const int FIELD_SIZE = 8; //Размер игрового поля
const int CHECKER_ROWS = 3; //Количество рядов шашек в начале игры

//НОМЕРА ТЕКСТУР
const int WHITE_TEXTURE = 0; //Белая шашка
const int BLACK_TEXTURE = 1; //Чёрная шашка
const int WHITE_Q_TEXTURE = 2; //Белая дамка
const int BLACK_Q_TEXTIRE = 3; //Чёрная дамка
const int SELECTED_TEXTURE = 0; //Выделенная шашка
const int UNSELECTED_TEXTURE = 1; //Шашка без выделения

//ПУТИ К ПАПКАМ
const std::string TEXTURES_PATH = "res\\textures\\"; //Путь к папке с текстурами
const std::string SOUNDS_PATH = "res\\sounds\\"; //Путь к папке со звуками

//ПУТИ К ФАЙЛАМ
const std::string FIELD = "field"; //Файл поля
const std::string CHECKERS = "checkers"; //Файл шашки

//РАСШИРЕНИЯ ФАЙЛОВ
const std::string TEXTURES_EXT = ".png"; //Расширение файлов текстур
const std::string SOUNDS_EXT = ".wav"; //Расширение файлов звуков
