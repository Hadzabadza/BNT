#pragma once
#include <string>
using namespace std;

//Различные дефолтные настройки

const float defaultScale = 2.0;           //Влияет на растяжку спрайтов по диагонали

#ifdef RELEASE							  //После того, как экзешник покинет папку с проектом, 
const string projectPath = "../";         //путь будет выставлен на тот, где он находится, 
#else                                     //поэтому я выставляю путь на родительскую папку
const string projectPath = "";
#endif

const string imageFolder = "data/image/"; //Путь к папке с картинками

const string nameFileFolder = "data/";    //Путь к папке с файлами для имён юнитов

const string mapsFolder = "data/maps/";   //Путь к папке с картами

const string fontsFolder = "data/";   //Путь к папке с шрифтами