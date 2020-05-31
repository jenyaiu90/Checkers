    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#pragma once

#include <string>

//ОСНОВНЫЕ
const std::string PROGRAM_NAME = "Checkers"; //Название программы
const std::string PROGRAM_VERSION = "Alpha 1.0.0"; //Версия программы
const int CHECKER_SIZE = 64; //Размер одной шашки
const int FIELD_SIZE = 8; //Размер игрового поля
const int CHECKER_ROWS = 3; //Количество рядов шашек в начале игры

//НОМЕРА ТЕКСТУР ШАШЕК
const int WHITE_TEXTURE = 0; //Белая шашка
const int BLACK_TEXTURE = 1; //Чёрная шашка
const int WHITE_Q_TEXTURE = 2; //Белая дамка
const int BLACK_Q_TEXTURE = 3; //Чёрная дамка
const int UNSELECTED_TEXTURE = 0; //Шашка без выделения
const int SELECTED_TEXTURE = 1; //Выделенная шашка

//КООРДИНАТЫ КНОПОК В НАСТРОЙКАХ
const int DEBUG_BT_POS[2] = { 2, 3 }; //Позиция кнопки режима отладки
const int TURN_BT_POS[2] = { 3, 3 }; //Позиция кнопки опции поворота доски
const int CLOSE_BT_POS[2] = { 4, 3 }; //Позиция кнопки закрытия
const int INFO_BT_POS[2] = { 5, 3 }; //Позиция кнопки информации

//КООРДИНАТЫ ТЕКСТУР КНОПОК НАСТРОЕК
const int UNSELECTED_BT_TEXTURE[2] = { 0, 0 }; //Фон не выделенной кнопки
const int SELECTED_BT_TEXTURE[2] = { 1, 0 }; //Фон выделенной кнопки
const int CLOSE_BT_TEXTURE[2] = { 2, 0 }; //Кнопка закрытия
const int TURN_BT_TEXTURE[2] = { 3, 0 }; //Кнопка опции поворота доски
const int INFO_BT_TEXTURE[2] = { 0, 1 }; //Кнопка информации
const int OPTIONS_BT_TEXTURE[2] = { 1, 1 }; //Кнопка настроек
const int DEBUG_BT_TEXTURE[2] = { 2, 1 }; //Кнопка режима отладки

//ПУТИ К ПАПКАМ
const std::string TEXTURES_PATH = "res\\textures\\"; //Путь к папке с текстурами
const std::string SOUNDS_PATH = "res\\sounds\\"; //Путь к папке со звуками
const std::string FONTS_PATH = "res\\fonts\\"; //Путь к папке со шрифтами

//ПУТИ К ФАЙЛАМ
const std::string LOG_FILE = "log"; //Файл лога
const std::string FIELD_FILE = "field"; //Файл поля
const std::string CHECKERS_FILE = "checkers"; //Файл шашки
const std::string LOGO_FILE = "logo"; //Файл логотипа
const std::string ICON_FILE = "icon"; //Файл иконки
const std::string OPTIONS_WINDOW_FILE = "options_window"; //Файл окна настроек
const std::string BUTTONS_FILE = "buttons"; //Файл кнопок
const std::string FONT_FILE = "font"; //Файл шрифта

//РАСШИРЕНИЯ ФАЙЛОВ
const std::string TEXTURES_EXT = ".png"; //Расширение файлов текстур
const std::string SOUNDS_EXT = ".wav"; //Расширение файлов звуков
const std::string TEXT_EXT = ".txt"; //Расширение текстовых файлов
const std::string FONT_EXT = ".ttf"; //Расширение файлов шрифтов

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
const std::string D_INFO_OPEN = "info window is opened"; //Окно с информацией открыто
const std::string D_INFO_CLOSE = "info window is closed"; //Окно с информацией закрыто

//ИНФОРМАЦИЯ
const std::string I_START = "the program is started"; //Начало работы программы
const std::string I_END = "the program is closed"; //Работа программы завершена
const std::string I_GAME_START = "the game is started"; //Игра начата

//ПРЕДУПРЕЖДЕНИЯ
const std::string W_CLICK_OUT_OF_WINDOW = "a click out of the window is detected. That`s strange..."; //Обнаружено нажатие вне окна

//ОШИБКИ
const std::string E_NO_FILE = "file not found: "; //Файл не найден

//ТЕКСТ
const std::string INFO_TITLE = PROGRAM_NAME + ": Info"; //Заголовок окна информации
const std::string INFO_TEXT = PROGRAM_NAME + "\nversion: " + PROGRAM_VERSION + "\n\nSnegirSoft:\n\tjenyaiu90"; //Информация о программе