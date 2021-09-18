
#include "core/Game.h"

const bool HELP_ENABLED = true;
const char VERSION[] = "0.1";
const char USAGE[] = R"(glm
    Usage:
        basic_game --manifest=<path>
        basic_game --version
        basic_game --help

    Options:
        --manifest=<path>
        --version
        --help
)";

int main(int argc, char* argv[])
{
    auto arguments = docopt::docopt(USAGE, { argv + 1, argv + argc }, HELP_ENABLED, VERSION);
    start_game(arguments["--manifest"].asString());
    return EXIT_SUCCESS;
}
