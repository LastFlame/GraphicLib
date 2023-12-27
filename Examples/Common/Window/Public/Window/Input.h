#pragma once

class Window;

enum class EInputAction : int {
    RELEASE,
    PRESS,
    REPEAT,
};

enum class EInputKey : int {
    MOUSE_LEFT,
    MOUSE_RIGHT,
    MOUSE_MIDDLE,
    MOUSE_BUTTON_4,
    MOUSE_BUTTON_5,
    MOUSE_BUTTON_6,
    MOUSE_BUTTON_7,
    SPACE,
    APOSTROPHE /* ' */,
    COMMA /* , */,
    MINUS /* - */,
    PERIOD /* . */,
    SLASH /* / */,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    SEMICOLON /* ; */,
    EQUAL /* = */,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    LEFT_BRACKET /* [ */,
    BACKSLASH /* \ */,
    RIGHT_BRACKET /* ] */,
    GRAVE_ACCENT /* ` */,
    WORLD_1 /* non-US #1 */,
    WORLD_2 /* non-US #2 */,
    ESCAPE,
    ENTER,
    TAB,
    BACKSPACE,
    INSERT,
    DELETE,
    RIGHT,
    LEFT,
    DOWN,
    UP,
    PAGE_UP,
    PAGE_DOWN,
    HOME,
    END,
    CAPS_LOCK,
    SCROLL_LOCK,
    NUM_LOCK,
    PRINT_SCREEN,
    PAUSE,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    F16,
    F17,
    F18,
    F19,
    F20,
    F21,
    F22,
    F23,
    F24,
    F25,
    KP_0,
    KP_1,
    KP_2,
    KP_3,
    KP_4,
    KP_5,
    KP_6,
    KP_7,
    KP_8,
    KP_9,
    KP_DECIMAL,
    KP_DIVIDE,
    KP_MULTIPLY,
    KP_SUBTRACT,
    KP_ADD,
    KP_ENTER,
    KP_EQUAL,
    LEFT_SHIFT,
    LEFT_CONTROL,
    LEFT_ALT,
    LEFT_SUPER,
    RIGHT_SHIFT,
    RIGHT_CONTROL,
    RIGHT_ALT,
    RIGHT_SUPER,
    MENU,
};

struct MousePosition {
    double X{};
    double Y{};
    bool operator==(const MousePosition& other) const {
        constexpr double epsilon = 0.01;
        const bool xIsEqual = other.X == X + epsilon || other.X == X - epsilon;
        const bool yIsEqual = other.Y == Y + epsilon || other.Y == Y - epsilon;
        return xIsEqual && yIsEqual;
    }
    bool operator!=(const MousePosition& other) const { return !(*this == other); }
    MousePosition operator+(const MousePosition& other) const { return {X + other.X, Y + other.Y}; }
    MousePosition operator-(const MousePosition& other) const { return {X - other.X, Y - other.Y}; }
};

class Input final {
public:
    using KeyInputCallback = void (*)(EInputKey, EInputAction, void*);

    Input() = default;
    Input(const Input& other) = delete;
    Input(Input&& other) = delete;
    Input& operator=(const Input& other) = delete;
    Input& operator=(const Input&& other) = delete;
    ~Input();
    bool Initialise(const Window& window);
    void Shutdown();
    void SetKeyInputCallback(KeyInputCallback keyCallback, void* userData);
    bool IsKeyPressed(EInputKey key);
    bool IsKeyReleased(EInputKey key);
    MousePosition GetMousePosition();
};