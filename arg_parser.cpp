#include "arg_parser.h"

QScopedPointer<QCommandLineParser> parse_args(const QCoreApplication& app) {
    auto parser = new QCommandLineParser;

    parser->setApplicationDescription("Students rating app.");
    parser->addHelpOption();

//    parser->addPositionalArgument("course", "Choose course from list", "COURSE");

    parser->addOption({
        "course",
        "Choose course from list",
        "COURSE",
        "пми-22.json"
    });

    parser->addOption({
        "criteria",
        "marks, attendance or pluses",
        "CRITERIA",
        "average"
    });

    parser->addOption({
        "table",
        "Output list in table."
    });

    parser->addOption({
        "sort",
        "asc or desc",
        "SORT",
        "average=desc"
    });

    parser->process(app);

    if (!parser->parse(QCoreApplication::arguments()))
        error(parser->errorText().toLatin1().toStdString());

    return QScopedPointer(parser);
}