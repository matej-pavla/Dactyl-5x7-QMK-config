1. Place the contents of this folder under `keyboards/handwired/red_beast`
2. Upload `handwired_dactyl_manuform_5x7_layout_5x7_mine.json` to the QMK configurator, and export a new one
3. Replace text occurence of `dactyl_manuform/5x7` in the exported file to `red_beast`
4. `qmk flash -bl dfu handwired_red_beast_default.json` in the root of a qmk firmware fork
