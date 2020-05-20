    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Constants.h                 //
////////////////////////////////////////

#pragma once

#include <string>

//��������
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
const std::string FIELD = "field"; //���� ����
const std::string CHECKERS = "checkers"; //���� �����

//���������� ������
const std::string TEXTURES_EXT = ".png"; //���������� ������ �������
const std::string SOUNDS_EXT = ".wav"; //���������� ������ ������
