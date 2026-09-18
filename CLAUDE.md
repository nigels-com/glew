# Notes for Claude Code

## `auto/glfixes` — keep it, REGAL support continues

`auto/glfixes` (cloned from `nigels-com/glfixes` in `auto/Makefile`) supplies extension specs
that the official Khronos registry doesn't have natively. Checked what's actually still
dependent on it:

- **REGAL: 100% dependent on glfixes.** The official Khronos `OpenGL-Registry` has zero REGAL
  extension files at all — the `extensions/REGAL/` directory only exists in a checkout because
  the Makefile copies it in from glfixes. All 7 `GL_REGAL_*` symbols in `include/GL/glew.h`
  come exclusively from there.
- **ANGLE: mostly redundant now, one straggler.** Khronos picked up 9 of glfixes' 10 ANGLE
  extensions natively at some point (properly named `ANGLE_*.txt`, git-tracked upstream).
  `ANGLE_timer_query` is still genuinely absent from Khronos and only available via glfixes.

Decision: **REGAL support continues** — don't drop `glfixes` or remove the `GL_REGAL_*`
extensions from GLEW's generated output, even though the Regal project itself looks dormant.
The `cp -r glfixes/gl/specs/ANGLE ...` step could in principle be narrowed to just
`timer_query.txt` since Khronos now covers the rest, but that's an optional tidy, not required.
