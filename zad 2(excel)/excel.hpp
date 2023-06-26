#ifndef EXCEL_HPP
#define EXCEL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/**
 * @brief The direction enum specifies the possible directions.
 */
enum direction { x = 1, y = 1, lev = 0 };

/**
 * @brief The Komorka class is an abstract base class representing a cell in the spreadsheet.
 */
class Komorka 
{
public:
    /**
     * @brief Virtual destructor for the Komorka class.
     */
    virtual ~Komorka() {};

    /**
     * @brief Returns the content of the cell.
     * @return The content of the cell as a string.
     */
    virtual std::string getZawartosc() const = 0;

    /**
     * @brief Sets the content of the cell.
     * @param zawartosc The content to be set in the cell.
     */
    virtual void setZawartosc(const std::string& zawartosc) = 0;
};

/**
 * @brief The KomorkaTekstowa class represents a text cell in the spreadsheet.
 */
class KomorkaTekstowa : public Komorka
{
private:
    std::string zawartosc;

public:
    /**
     * @brief Returns the content of the text cell.
     * @return The content of the text cell as a string.
     */
    std::string getZawartosc() const override { return zawartosc; }

    /**
     * @brief Sets the content of the text cell.
     * @param zawartosc The content to be set in the text cell.
     */
    void setZawartosc(const std::string& zawartosc) override { this->zawartosc = zawartosc; }
};

/**
 * @brief The KomorkaLiczbowy class represents a numeric cell in the spreadsheet.
 */
class KomorkaLiczbowy : public Komorka
{
private:
    int zawartosc;

public:
    /**
     * @brief Returns the content of the numeric cell.
     * @return The content of the numeric cell as a string.
     */
    std::string getZawartosc() const override { return std::to_string(zawartosc); }

    /**
     * @brief Sets the content of the numeric cell.
     * @param zawartosc The content to be set in the numeric cell.
     */
    void setZawartosc(const std::string& zawartosc) override { this->zawartosc = std::stoi(zawartosc); }
};

/**
 * @brief The Excel class represents the spreadsheet.
 */
class Excel 
{
private:
    using db = std::vector<std::vector<Komorka*>>;

    db excelVector;

public:
    /**
     * @brief Expands the size of the spreadsheet.
     * @param x The number of columns to add.
     * @param y The number of rows to add.
     */
    void expand(int x, int y);

    /**
     * @brief Retrieves the content of a specific cell.
     * @param x The column index of the cell.
     * @param y The row index of the cell.
     * @return The content of the cell as a string.
     */
    std::string show_cell(int x, int y); 

    /**
     * @brief Sets the content of a specific cell.
     * @param x The column index of the cell.
     * @param y The row index of the cell.
     * @param to_set The content to be set in the cell.
     */
    void set_cell(int x, int y, const std::string& to_set);

    /**
     * @brief Clears the content of a specific cell.
     * @param x The column index of the cell.
     * @param y The row index of the cell.
     */
    void clear_cell(int x, int y);

    /**
     * @brief Destroys the spreadsheet, freeing the allocated memory.
     */
    void destroy();

    /**
     * @brief Calculates the sum of cell contents based on the given direction and range.
     * @param d The direction of summing (x, y, or lev).
     * @param t The starting index of the range.
     * @param s The ending index of the range.
     * @param f The fixed index for the range.
     * @return The sum of the cell contents as an integer.
     */
    int sum_komorki(direction d, int t, int s, int f);

    /**
     * @brief Saves the spreadsheet to a file.
     * @param filename The name of the file to save to.
     */
    void save_to_file(const std::string& filename);

    /**
     * @brief Loads the spreadsheet from a file.
     * @param filename The name of the file to load from.
     */
    void load_from_file(const std::string& filename);

    /**
     * @brief Constructor for the Excel class.
     * @param x The initial number of columns in the spreadsheet.
     * @param y The initial number of rows in the spreadsheet.
     */
    Excel(int x, int y);

    /**
     * @brief Destructor for the Excel class.
     */
    ~Excel();
};

/**
 * @brief Overload of the >> operator for reading direction values from an input stream.
 * @param is The input stream.
 * @param d The direction value to be read.
 * @return The input stream after reading the direction value.
 */
std::istream& operator>>(std::istream& is, direction& d);

#endif
