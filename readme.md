# EMombay-vial

Vial-enabled counterpart of the [EMombay](../EMombay) keymap for the `ymdk/id75`. Same 7-layer layout (Workman/QWERTY/Symbols/Util/Numpad/Adjust/Game) and RGB layer indication, plus `VIA_ENABLE`/`VIAL_ENABLE`/`VIALRGB_ENABLE` and a `vial.json` so it can be live-edited from the [Vial](https://get.vial.today) app.

## Building

```
make ymdk/id75/rp2040:EMombay-vial
```

The `rp2040` variant is pin-for-pin identical to the `ymdk/id75v3rp` board (same matrix pins, WS2812 on GP2, ROW2COL), so the resulting `.uf2` runs on that hardware too. The `f103` variant also builds this keymap but has less flash headroom for the Vial macro/combo/tap-dance entry counts in `config.h`.

## Modernization notes (2026-07)

- **Built-in keycodes in the default keymap:** the grid now uses `MO(...)` for momentary layers, `PDF(_WORK)`/`PDF(_QWERTY)` for the persistent default layer, and `EE_CLR` for EEPROM reset. The named custom keycodes (WRKMN, QWERTY, SYMB, UTIL, NUM, ADJ, GAME, EPRM, ALTTAB) are still defined and handled, so they appear in Vial's keycode picker and work when assigned from the app.
- **Bug fix:** the bottom-right key was `TT(NUM)` using the old custom keycode instead of the layer index; it is now `TT(_NUM)` and toggles the Numpad layer as intended.
- **Alt+Tab uses the deferred executor** (`DEFERRED_EXEC_ENABLE`) instead of polling a timer in `matrix_scan_user()` — Alt is released 1 s after the last tap.
- **RGB layer tint no longer writes EEPROM:** layer changes use `rgb_matrix_sethsv_noeeprom()` via a per-layer color table, so rapid layer switching can't wear the flash-emulated EEPROM. Default-layer switches (Workman ↔ QWERTY) also retint now. The Game layer uses its own `RGB_MATRIX_COLOR_LAYER_6` color, set to red (hue 0) to match what it used to inherit from layer 2. `keyboard_post_init_user()` also calls `rgb_matrix_enable_noeeprom()` before the initial tint — otherwise, if EEPROM's saved `enable` flag was ever left off (e.g. from before this feature existed), the layer color would be set but nothing would light up until the Vial app's RGB tab was opened once to flip it back on.
- **Vial capacity bumped** to 32 macros, 8 combos, and 8 key overrides (parity with the `ymdk/id75v3rp` vial keymap).
- **Underglow only:** this board has no per-key RGB LEDs, so keypress-reactive and heatmap effects are left disabled; the RGB Matrix / VialRGB support drives the 14 underglow LEDs, which still show the per-layer tint.
- **Eager debounce:** `DEBOUNCE_TYPE = asym_eager_defer_pk` replaces the default `sym_defer_g`, which held back every press *and* release by the 5 ms debounce window. Presses now report immediately (~5 ms lower press latency); releases are still deferred 5 ms per key, so release chatter can't cause double-types or stuck keys.
- **Trimmed animation set:** the keyboard-level json compiles in ~30 RGB Matrix animations; `config.h` now `#undef`s all but an underglow-friendly set (solid color, breathing, cycle all/left-right/up-down, rainbow moving chevron, hue wave, gradient left-right). This shrinks the firmware, keeps `RM_NEXT` cycling only useful modes, and the Vial app's effect list follows automatically. If the effect saved in EEPROM was one of the removed ones, reselect an effect in Vial after flashing.

**Tap dance:** the original keymap's 3 hardcoded tap dances (`TD_FUN`, `TD_3EQ`, `TD_2EQ` — tap/double-tap for `=>`/`() => {}`, `===`/`!==`, `==`/`!=`) were removed from `keymap.c`, since Vial's own tap-dance system owns the `tap_dance_actions[]` array and can't coexist with a hardcoded one using custom C functions. The 3 keys on the Symbols layer that used to hold those dances are now `KC_NO` placeholders — recreate the same behavior after flashing using Vial's **Tap Dance** tab (bind on-tap/on-double-tap to keycodes or **Macro** tab entries for the multi-character output), then reassign those 3 keys to the resulting `TD(n)` keycodes.
