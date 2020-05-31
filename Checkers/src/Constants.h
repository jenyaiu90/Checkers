    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#pragma once

#include <string>

//��������
const std::string PROGRAM_NAME = "Checkers"; //�������� ���������
const std::string PROGRAM_VERSION = "Alpha 1.0.0"; //������ ���������
const int CHECKER_SIZE = 64; //������ ����� �����
const int FIELD_SIZE = 8; //������ �������� ����
const int CHECKER_ROWS = 3; //���������� ����� ����� � ������ ����

//������ ������� �����
const int WHITE_TEXTURE = 0; //����� �����
const int BLACK_TEXTURE = 1; //׸���� �����
const int WHITE_Q_TEXTURE = 2; //����� �����
const int BLACK_Q_TEXTURE = 3; //׸���� �����
const int UNSELECTED_TEXTURE = 0; //����� ��� ���������
const int SELECTED_TEXTURE = 1; //���������� �����

//���������� ������ � ����������
const int DEBUG_BT_POS[2] = { 2, 3 }; //������� ������ ������ �������
const int TURN_BT_POS[2] = { 3, 3 }; //������� ������ ����� �������� �����
const int CLOSE_BT_POS[2] = { 4, 3 }; //������� ������ ��������
const int INFO_BT_POS[2] = { 5, 3 }; //������� ������ ����������

//���������� ������� ������ ��������
const int UNSELECTED_BT_TEXTURE[2] = { 0, 0 }; //��� �� ���������� ������
const int SELECTED_BT_TEXTURE[2] = { 1, 0 }; //��� ���������� ������
const int CLOSE_BT_TEXTURE[2] = { 2, 0 }; //������ ��������
const int TURN_BT_TEXTURE[2] = { 3, 0 }; //������ ����� �������� �����
const int INFO_BT_TEXTURE[2] = { 0, 1 }; //������ ����������
const int OPTIONS_BT_TEXTURE[2] = { 1, 1 }; //������ ��������
const int DEBUG_BT_TEXTURE[2] = { 2, 1 }; //������ ������ �������

//���� � ������
const std::string TEXTURES_PATH = "res\\textures\\"; //���� � ����� � ����������
const std::string SOUNDS_PATH = "res\\sounds\\"; //���� � ����� �� �������
const std::string FONTS_PATH = "res\\fonts\\"; //���� � ����� �� ��������

//���� � ������
const std::string LOG_FILE = "log"; //���� ����
const std::string FIELD_FILE = "field"; //���� ����
const std::string CHECKERS_FILE = "checkers"; //���� �����
const std::string LOGO_FILE = "logo"; //���� ��������
const std::string ICON_FILE = "icon"; //���� ������
const std::string OPTIONS_WINDOW_FILE = "options_window"; //���� ���� ��������
const std::string BUTTONS_FILE = "buttons"; //���� ������
const std::string FONT_FILE = "font"; //���� ������

//���������� ������
const std::string TEXTURES_EXT = ".png"; //���������� ������ �������
const std::string SOUNDS_EXT = ".wav"; //���������� ������ ������
const std::string TEXT_EXT = ".txt"; //���������� ��������� ������
const std::string FONT_EXT = ".ttf"; //���������� ������ �������

//���
const std::string DEBUG = "Debug info: "; //���������� ����������
const std::string INFO = "Information: "; //����������
const std::string WARNING = "Warning: "; //��������������
const std::string ERROR = "An error occured: "; //������
const std::string REPORT = ". Please, report this error to the developers by email jenyaiu90@gmail.com"; //��������� �� ������

//���������� ����������
const std::string D_ENABLE = "debug mode enable"; //������� ����� �������
const std::string D_DISABLE = "debug mode disable"; //�������� ����� �������
const std::string D_FILE_LOADED = "file is loaded: "; //���� ��������
const std::string D_R_MANAGER_UNLOADED = "resource manager is unloaded"; //��������� �������� ������
const std::string D_CHECKER_MOVE = "a checker is moved to "; //����� ����������
const std::string D_FIELD_CREATED = "the field is created"; //������� ���� �������
const std::string D_INFO_OPEN = "info window is opened"; //���� � ����������� �������
const std::string D_INFO_CLOSE = "info window is closed"; //���� � ����������� �������

//����������
const std::string I_START = "the program is started"; //������ ������ ���������
const std::string I_END = "the program is closed"; //������ ��������� ���������
const std::string I_GAME_START = "the game is started"; //���� ������

//��������������
const std::string W_CLICK_OUT_OF_WINDOW = "a click out of the window is detected. That`s strange..."; //���������� ������� ��� ����

//������
const std::string E_NO_FILE = "file not found: "; //���� �� ������

//�����
const std::string INFO_TITLE = PROGRAM_NAME + ": Info"; //��������� ���� ����������
const std::string INFO_TEXT = PROGRAM_NAME + "\nversion: " + PROGRAM_VERSION + "\n\nSnegirSoft:\n\tjenyaiu90"; //���������� � ���������