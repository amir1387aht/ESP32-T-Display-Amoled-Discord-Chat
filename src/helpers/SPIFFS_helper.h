#include <SPIFFS.h>
#include <FS.h>
#include <config.h>

#pragma once

#define BasePath "/web_pages/"

void SPIFFS_init(bool formatOnFail = false, bool formatOnce = true);
void listDir(const char *dirname, uint8_t levels = 0);
String readFile(const char *path);
void writeFile(const char *path, const char *message);
void appendFile(const char *path, const char *message);
void renameFile(const char *path1, const char *path2);
void deleteFile(const char *path);
bool fileExists(const char *path);