    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#pragma once

#include <string>

//��������
const std::string PROGRAM_NAME = "Checkers"; //�������� ���������
const int CHECKER_SIZE = 64; //������ ����� �����
const int FIELD_SIZE = 8; //������ �������� ����
const int CHECKER_ROWS = 3; //���������� ����� ����� � ������ ����

//������ �������
const int WHITE_TEXTURE = 0; //����� �����
const int BLACK_TEXTURE = 1; //׸���� �����
const int WHITE_Q_TEXTURE = 2; //����� �����
const int BLACK_Q_TEXTIRE = 3; //׸���� �����
const int SELECTED_TEXTURE = 0; //���������� �����
const int UNSELECTED_TEXTURE = 1; //����� ��� ���������

//���� � ������
const std::string TEXTURES_PATH = "res\\textures\\"; //���� � ����� � ����������
const std::string SOUNDS_PATH = "res\\sounds\\"; //���� � ����� �� �������

//���� � ������
const std::string LOG_FILE = "log"; //���� ����
const std::string FIELD_FILE = "field"; //���� ����
const std::string CHECKERS_FILE = "checkers"; //���� �����

//���������� ������
const std::string TEXTURES_EXT = ".png"; //���������� ������ �������
const std::string SOUNDS_EXT = ".wav"; //���������� ������ ������
const std::string TEXT_EXT = ".txt"; //���������� ��������� ������

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

//����������
const std::string I_START = "the program is started"; //������ ������ ���������
const std::string I_END = "the program is closed"; //������ ��������� ���������
const std::string I_GAME_START = "the game is started"; //���� ������

//������
const std::string E_NO_FILE = "file not found: "; //���� �� ������