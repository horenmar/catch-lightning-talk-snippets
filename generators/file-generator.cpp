#include <catch2/catch.hpp>

#include <string>
#include <fstream>

class LineGenerator : public Catch::Generators::IGenerator<std::string> {
    std::string m_line;
    std::ifstream m_stream;
public:
    LineGenerator(std::string const& file):
        m_stream(file) {
        if (!next()) {
            throw Catch::GeneratorException("Couldn't read a single line");
        }
    }

    std::string const& get() const override {
        return m_line;
    }
    
    bool next() override {
        return !!std::getline(m_stream, m_line);
    }
};

namespace ns {
    
Catch::Generators::GeneratorWrapper<std::string> lines(std::string const& file) {
    return Catch::Generators::GeneratorWrapper<std::string>(
        std::unique_ptr<Catch::Generators::IGenerator<std::string>>(
            new LineGenerator(file)
        )
    );
}

}

TEST_CASE("filter can convert types inside the generator expression", "[example][generator]") {
    auto coefficients = GENERATE(
        map([](std::string const& num) { return std::stod(num); },
        ns::lines("test-inputs/coefs.txt"))
    );
    REQUIRE(coefficients > 0);
}
