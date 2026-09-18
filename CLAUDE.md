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

## GLXEW.md — doc-generation bug, and extensions with no working spec link

`glew-2.3.1/doc/glxew.html` (the source for `GLXEW.md`) has a real bug: 64 of its 72 rows
were mistakenly linked to the *EGL* spec PDF (`eglspec.1.5.pdf`) instead of any real GLX page —
not just a dead link, a wrong one. `GLXEW.md` ignores those source links entirely and resolves
every extension from scratch against the local `auto/OpenGL-Registry` checkout (dedicated
`GLX_VENDOR_name.txt` files, or the combined-spec fallback for extensions documented alongside
their GL/WGL siblings in one file).

10 of 72 have no working link anywhere and are listed as plain, unlinked bullets:

- `ARB_context_flush_control`
- `ARB_create_context_profile`
- `ARB_fbconfig_float`
- `ARB_robustness_share_group_isolation`
- `ATI_pixel_format_float`
- `ATI_render_texture`
- `EXT_create_context_es_profile`
- `EXT_fbconfig_packed_float`
- `NV_vertex_array_range`
- `SUN_video_resize`

Notes:
- 8 of these 10 are the same names already found unresolvable while writing `HISTORY.md` —
  consistent cross-check that they're genuinely absent, not just missed.
- `ARB_fbconfig_float` looked like it might be a GLEW-side mix-up with the real
  `GLX_SGIX_fbconfig_float` (same feature, different vendor tag), but that file's own Name
  Strings section only claims `GLX_SGIX_fbconfig_float` — the ARB name isn't listed as an
  alias anywhere, so no substitution was made.
- `NV_vertex_array_range` exists as a GL-only extension (`NV_vertex_array_range.txt`) but that
  spec doesn't list a GLX name string, so the GLX-specific variant genuinely has no page.

If a working link ever turns up for any of these, update the corresponding bullet in
`GLXEW.md`.

## EGLEW.md — extensions with only a generic spec-PDF link

`glew-2.3.1/doc/eglew.html` (the source for `EGLEW.md`) links *every* one of its 166 rows to
the same generic EGL 1.5 spec PDF, not a per-extension page. `EGLEW.md` replaces that with a
dedicated Khronos page per extension wherever one exists in the local `auto/EGL-Registry` (or
`auto/OpenGL-Registry` for extensions documented in a combined GL/WGL/GLX/EGL spec) — 145 of
166 got a real, specific link this way.

21 of 166 have no dedicated page anywhere and still fall back to the generic spec PDF (these
are *linked*, just not specifically — not the same situation as `GLEW.md`/`GLXEW.md`'s plain
unlinked bullets):

- `EGL_EXT_gl_colorspace_bt2020_hlg`, `EGL_EXT_gl_colorspace_bt2020_pq`,
  `EGL_EXT_gl_colorspace_display_p3_linear`
- `EGL_EXT_output_drm`, `EGL_EXT_output_openwf`
- `EGL_KHR_client_get_all_proc_addresses`, `EGL_KHR_gl_renderbuffer_image`,
  `EGL_KHR_gl_texture_2D_image`, `EGL_KHR_gl_texture_3D_image`,
  `EGL_KHR_gl_texture_cubemap_image`, `EGL_KHR_stream_attrib`
- `EGL_NOK_swap_region`
- `EGL_NV_quadruple_buffer`, `EGL_NV_triple_buffer`, `EGL_NV_stream_cross_display`,
  `EGL_NV_stream_cross_object`, `EGL_NV_stream_cross_partition`, `EGL_NV_stream_cross_process`,
  `EGL_NV_stream_cross_system`, `EGL_NV_stream_socket_inet`, `EGL_NV_stream_socket_unix`

Most of these are the same names already found unresolvable while writing `HISTORY.md` —
consistent cross-check. If a dedicated page ever turns up for any of these, update the
corresponding bullet in `EGLEW.md`.

## WGLEW.md — fully resolved

No note needed here: all 57 extensions resolved to a specific, working Khronos page. The
source (`glew-2.3.1/doc/wglew.html`) already had correct per-extension links for 56 of them;
the one exception (`WGL_NV_gpu_affinity`, pointing at an old NVIDIA download URL) had a
Khronos page available and was switched to it.

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
