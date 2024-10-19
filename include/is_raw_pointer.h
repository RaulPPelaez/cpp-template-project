#pragma once
namespace homework {

  /**
   * @brief A class that holds a boolean value that is true only if T is a raw pointer.
   *
   * @tparam T The type to check.
   */
  template <typename T>
  struct IsRawPointer {
    static constexpr bool value = false;
  };

  template <typename T>
  struct IsRawPointer<T*> {
    static constexpr bool value = true;
  };

  template <typename T>
  constexpr bool IsRawPointer_v = IsRawPointer<T>::value;


} // namespace homework
