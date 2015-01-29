/*
 * Very Simple Game Engine
 *
 * Display Mode class
 *
 * Holds Window display mode (width, height, refresh rate)
 *
 */

#ifndef VSGE_DISPLAYMODE_H
#define VSGE_DISPLAYMODE_H

#include <vector>

#include <SDL_video.h>

#include <VSGE/util/types.h>

namespace vsge
{

class DisplayMode
{
public:
  /**
   * \brief Default constructor
   */
  DisplayMode();

  /**
   * \brief Constructor using SDL_DisplayMode
   */
  explicit DisplayMode(SDL_DisplayMode mode);

  /**
   * \brief Get the current desktop video mode
   *
   * \return Current desktop display mode
   */
  static DisplayMode getCurrentMode();

  /**
   * \brief Retrieve all available fullscreen display modes
   * \return Array containing all supported fullscreen modes
   */
  static const std::vector<DisplayMode>& getFullscreenModes();

  /**
   * \brief Tell whether or not the display mode is valid for fullscreen
   *
   * \return True if the display mode is valid for fullscreen
   */
  bool isValid() const;

  /**
   * \brief Get display mode width
   * \return Width
   */
  int getWidth() const;

  /**
   * \brief Get display mode height
   * \return Height
   */
  int getHeight() const;

  /**
   * \brief Get display mode refresh rate
   * \return Refresh rate
   */
  int getRefreshRate() const;

  /**
   * \brief Get display mode bpp
   * \return Bits per pixel
   */
  int getBPP() const;

  /**
   * \brief Get display format
   * \return Display format (uint32). SDL specific
   */
  uint32 getFormat() const;

protected:
private:
  /**
   * \brief Get display mode format
   */

  SDL_DisplayMode mode_; /**< SDL display mode structure */
};

/**
 * \relates DisplayMode
 * \brief Overload of == operator to compare two display modes
 *
 * \param lhs Left operand (a display mode)
 * \param rhs Right operand (a display mode)
 *
 * \return True if modes are equal
 */
bool operator ==(const DisplayMode& lhs, const DisplayMode& rhs);

/**
 * \relates DisplayMode
 * \brief Overload of != operator to compare two display modes
 *
 * \param lhs Left operand (a display mode)
 * \param rhs Right operand (a display mode)
 *
 * \return True if modes are not equal
 */
bool operator !=(const DisplayMode& lhs, const DisplayMode& rhs);

/**
 * \relates DisplayMode
 * \brief Overload of < operator to compare two display modes
 *
 * \param lhs Left operand (a display mode)
 * \param rhs Right operand (a display mode)
 *
 * \return True if \a lhs is lesser that \a rhs
 */
bool operator <(const DisplayMode& lhs, const DisplayMode& rhs);

/**
 * \relates DisplayMode
 * \brief Overload of > operator to compare two display modes
 *
 * \param lhs Left operand (a display mode)
 * \param rhs Right operand (a display mode)
 *
 * \return True if \a lhs is greater that \a rhs
 */
bool operator >(const DisplayMode& lhs, const DisplayMode& rhs);

/**
 * \relates DisplayMode
 * \brief Overload of <= operator to compare two display modes
 *
 * \param lhs Left operand (a display mode)
 * \param rhs Right operand (a display mode)
 *
 * \return True if \a lhs is lesser or equal that \a rhs
 */
bool operator <=(const DisplayMode& lhs, const DisplayMode& rhs);

/**
 * \relates DisplayMode
 * \brief Overload of >= operator to compare two display modes
 *
 * \param lhs Left operand (a display mode)
 * \param rhs Right operand (a display mode)
 *
 * \return True if \a lhs is greater or equal that \a rhs
 */
bool operator >=(const DisplayMode& lhs, const DisplayMode& rhs);

}

#endif //VSGE_DISPLAYMODE_H
