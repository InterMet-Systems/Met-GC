#include "MetConfigParser.h"
#include <QRegExp>
#include <QDebug>

bool MetConfigParser::parseFile(QString fileContent) {
    QStringList lines = fileContent.split("\r\n");
    QString currentSection;

    for (QString& line : lines) {
        QString trimmedLine = line.trimmed();

        // Skip empty lines and comments (lines starting with ; or #)
        if (trimmedLine.isEmpty() || trimmedLine.startsWith(';') || trimmedLine.startsWith('#')) {
            continue;
        }

        // Check if it's a section header (e.g., [FlightData])
        if (trimmedLine.startsWith('[') && trimmedLine.endsWith(']')) {
            currentSection = trimmedLine.mid(1, trimmedLine.length() - 2);
        }
        else {
            // Parse key-value pair (key=value)
            int equalPos = trimmedLine.indexOf('=');
            if (equalPos != -1) {
                QString key = trimmedLine.left(equalPos).trimmed();
                QString value = trimmedLine.mid(equalPos + 1).trimmed();
                sections[currentSection][key] = value;
            }
        }
    }

    return true;
}

QMap<QString, QMap<QString, QString>> MetConfigParser::getSections() {
    return sections;
}

void MetConfigParser::setSections(QMap<QString, QMap<QString, QString>> newSections) {
    sections = newSections;
}

QString MetConfigParser::print() {
    QString result;

    // Iterate through sections
    for (auto it = sections.begin(); it != sections.end(); ++it) {
        result += "[" + it.key() + "]\r\n";

        // Iterate through key-value pairs in each section
        for (auto kv = it.value().begin(); kv != it.value().end(); ++kv) {
            result += kv.key() + "=" + kv.value() + "\r\n";
        }
    }

    return result;
}

QString MetConfigParser::toIniString() {
    QString result;

    // Iterate through sections
    for (auto it = sections.begin(); it != sections.end(); ++it) {
        result += "[" + it.key() + "]\r\n";

        // Iterate through key-value pairs in each section
        for (auto kv = it.value().begin(); kv != it.value().end(); ++kv) {
            result += kv.key() + "=" + kv.value() + "\r\n";
        }
        result += "\r\n"; // Blank line after each section
    }

    // Remove the last blank line (if any)
    if (!result.isEmpty() && result.endsWith("\r\n")) {
        result.chop(1);
    }

    return result;
}
