#ifndef METCONFIGPARSER_H
#define METCONFIGPARSER_H

#include <QString>
#include <QMap>
#include <QTextStream>

class MetConfigParser {
    public:
        // Stores sections with key-value pairs
        QMap<QString, QMap<QString, QString>> sections;

        // Parses the INI content from a string representation of the file
        bool parseFile(QString fileContent);

        // Getter for the parsed sections map
        QMap<QString, QMap<QString, QString>> getSections();

        // Setter for the sections map
        void setSections(QMap<QString, QMap<QString, QString>> newSections);

        // Returns a string representation of the parsed INI content
        QString print();

        // Converts the map representation of the INI data back to a string
        QString toIniString();
};

#endif //METCONFIGPARSER_H