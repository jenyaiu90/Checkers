    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#pragma once

#include <string>

//ОСНОВНЫЕ
const std::string PROGRAM_NAME = "Checkers"; //Название программы
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
const std::string LOG_FILE = "log"; //Файл лога
const std::string FIELD_FILE = "field"; //Файл поля
const std::string CHECKERS_FILE = "checkers"; //Файл шашки

//РАСШИРЕНИЯ ФАЙЛОВ
const std::string TEXTURES_EXT = ".png"; //Расширение файлов текстур
const std::string SOUNDS_EXT = ".wav"; //Расширение файлов звуков
const std::string TEXT_EXT = ".txt"; //Расширение текстовых файлов

//ЛОГ
const std::string DEBUG = "Debug info: "; //Отладочная информация
const std::string INFO = "Information: "; //Информация
const std::string WARNING = "Warning: "; //Предупреждение
const std::string ERROR = "An error occured: "; //Ошибка
const std::string REPORT = ". Please, report this error to the developers by email jenyaiu90@gmail.com"; //Сообщение об ошибке

//ОТЛАДОЧНАЯ ИНФОРМАЦИЯ
const std::string D_ENABLE = "debug mode enable"; //Включен режим отладки
const std::string D_DISABLE = "debug mode disable"; //Выключен режим отладки
const std::string D_FILE_LOADED = "file is loaded: "; //Файл загружен
const std::string D_R_MANAGER_UNLOADED = "resource manager is unloaded"; //Диспетчер ресурсов закрыт
const std::string D_CHECKER_MOVE = "a checker is moved to "; //Шашка перемещена
const std::string D_FIELD_CREATED = "the field is created"; //Игровое поле создано

//ИНФОРМАЦИЯ
const std::string I_START = "the program is started"; //Начало работы программы
const std::string I_END = "the program is closed"; //Работа программы завершена
const std::string I_GAME_START = "the game is started"; //Игра начата

//ОШИБКИ
const std::string E_NO_FILE = "file not found: "; //Файл не найден