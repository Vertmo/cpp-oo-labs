#include "utils.hpp"

/**
 * Load json document from specified file name
 */
QJsonDocument loadJson(const std::string & fileName) {
   QFile file(QString::fromStdString(fileName));
   file.open(QIODevice::ReadOnly | QIODevice::Text);
   return QJsonDocument::fromJson(file.readAll());
}

