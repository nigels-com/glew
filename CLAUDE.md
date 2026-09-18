# Notes for Claude Code

## GLEW.md — extensions with no working spec link

`GLEW.md` (converted from `glew-2.3.1/doc/glew.html`) links each supported extension to its
registry spec. Seven of these have no known working link anywhere and are listed as plain,
unlinked bullets:

- `ATIX_point_sprites`
- `ATIX_texture_env_route`
- `ATIX_vertex_shader_output_point_size`
- `EXT_texture_edge_clamp`
- `EXT_texture_rectangle`
- `SUN_read_video_pixels`
- `WIN_swap_hint`

Investigated and confirmed dead (not just moved):
- Their original hosts (ati.com, opengl.org, developer.apple.com, wwws.sun.com,
  msdn.microsoft.com) either 404, redirect to a generic homepage/docs landing page unrelated
  to the specific extension, or fail to resolve at all.
- No file matching these names (under any vendor prefix, and checked for combined/renamed
  specs too) exists in the local `auto/OpenGL-Registry` checkout.
- The Internet Archive Wayback Machine was rate-limiting lookups when last tried, and is not
  reachable via the WebFetch tool at all — worth another attempt later as a source of archived
  copies if these should get *some* link rather than none.

If a working link ever turns up for any of these, update the corresponding bullet in
`GLEW.md`.

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
