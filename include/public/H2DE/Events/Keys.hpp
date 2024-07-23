#pragma once

namespace H2DE
{
    /**
     * @enum Key
     * @brief Enum class for keyboard keys.
     *
     * This enum class defines the various keys on a keyboard, including
     * letters, numbers, function keys, and control keys. Each key is
     * represented by a unique value.
     */
    enum class Key {
        Unknown = -1, /**< Unknown key */
        A = 0,        /**< The `A` key */
        B,            /**< The `B` key */
        C,            /**< The `C` key */
        D,            /**< The `D` key */
        E,            /**< The `E` key */
        F,            /**< The `F` key */
        G,            /**< The `G` key */
        H,            /**< The `H` key */
        I,            /**< The `I` key */
        J,            /**< The `J` key */
        K,            /**< The `K` key */
        L,            /**< The `L` key */
        M,            /**< The `M` key */
        N,            /**< The `N` key */
        O,            /**< The `O` key */
        P,            /**< The `P` key */
        Q,            /**< The `Q` key */
        R,            /**< The `R` key */
        S,            /**< The `S` key */
        T,            /**< The `T` key */
        U,            /**< The `U` key */
        V,            /**< The `V` key */
        W,            /**< The `W` key */
        X,            /**< The `X` key */
        Y,            /**< The `Y` key */
        Z,            /**< The `Z` key */
        Num0,         /**< The `0` key on the number pad */
        Num1,         /**< The `1` key on the number pad */
        Num2,         /**< The `2` key on the number pad */
        Num3,         /**< The `3` key on the number pad */
        Num4,         /**< The `4` key on the number pad */
        Num5,         /**< The `5` key on the number pad */
        Num6,         /**< The `6` key on the number pad */
        Num7,         /**< The `7` key on the number pad */
        Num8,         /**< The `8` key on the number pad */
        Num9,         /**< The `9` key on the number pad */
        Escape,       /**< The `Escape` key */
        LControl,     /**< The `left` Control key */
        LShift,       /**< The `left` Shift key */
        LAlt,         /**< The `left` Alt key */
        LSystem,      /**< The `left` OS specific key (e.g., Windows key) */

        RControl, /**< The `right` Control key */
        RShift,   /**< The `right` Shift key */
        RAlt,     /**< The `right` Alt key */
        RSystem,  /**< The `right` OS specific key (e.g., Windows key) */

        Menu,       /**< The `Menu` key */
        LBracket,   /**< The `[` key */
        RBracket,   /**< The `]` key */
        Semicolon,  /**< The `;` key */
        Comma,      /**< The `,` key */
        Period,     /**< The `.` key */
        Apostrophe, /**< The `'` key */
        Slash,      /**< The `/` key */
        Backslash,  /**< The `\` key */
        Grave,      /**< The ``` key */
        Equal,      /**< The `=` key */
        Hyphen,     /**< The `-` key */
        Space,      /**< The `Space` key */
        Enter,      /**< The `Enter`/Return key */
        Backspace,  /**< The `Backspace` key */
        Tab,        /**< The `Tab` key */
        PageUp,     /**< The `Page` Up key */
        PageDown,   /**< The `Page` Down key */
        End,        /**< The `End` key */
        Home,       /**< The `Home` key */
        Insert,     /**< The `Insert` key */
        Delete,     /**< The `Delete` key */
        Add,        /**< The `+` key on the number pad */
        Subtract,   /**< The `-` key on the number pad */
        Multiply,   /**< The `*` key on the number pad */
        Divide,     /**< The `/` key on the number pad */
        Left,       /**< The `left` arrow key */
        Right,      /**< The `right` arrow key */
        Up,         /**< The `up` arrow key */
        Down,       /**< The `down` arrow key */
        Numpad0,    /**< The `0` key on the number pad */
        Numpad1,    /**< The `1` key on the number pad */
        Numpad2,    /**< The `2` key on the number pad */
        Numpad3,    /**< The `3` key on the number pad */
        Numpad4,    /**< The `4` key on the number pad */
        Numpad5,    /**< The `5` key on the number pad */
        Numpad6,    /**< The `6` key on the number pad */
        Numpad7,    /**< The `7` key on the number pad */
        Numpad8,    /**< The `8` key on the number pad */
        Numpad9,    /**< The `9` key on the number pad */
        F1,         /**< The `F1` key */
        F2,         /**< The `F2` key */
        F3,         /**< The `F3` key */
        F4,         /**< The `F4` key */
        F5,         /**< The `F5` key */
        F6,         /**< The `F6` key */
        F7,         /**< The `F7` key */
        F8,         /**< The `F8` key */
        F9,         /**< The `F9` key */
        F10,        /**< The `F10` key */
        F11,        /**< The `F11` key */
        F12,        /**< The `F12` key */
        F13,        /**< The `F13` key */
        F14,        /**< The `F14` key */
        F15,        /**< The `F15` key */
        Pause,      /**< The `Pause` key */

        KeyCount, /**< Total number of keyboard keys */
    };
};  // namespace H2DE
