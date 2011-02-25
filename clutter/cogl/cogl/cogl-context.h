/*
 * Cogl
 *
 * An object oriented GL/GLES Abstraction/Utility Layer
 *
 * Copyright (C) 2010 Intel Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *  Robert Bragg <robert@linux.intel.com>
 *
 */

#if !defined(__COGL_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <cogl/cogl.h> can be included directly."
#endif

#ifndef __COGL_CONTEXT_H__
#define __COGL_CONTEXT_H__

#include <cogl/cogl-display.h>

#ifdef COGL_HAS_EGL_SUPPORT
#ifdef COGL_HAS_GLES1
#include <GLES/gl.h>
#include <GLES/egl.h>
#else
#include <EGL/egl.h>
#define NativeDisplayType EGLNativeDisplayType
#define NativeWindowType EGLNativeWindowType
#endif
#endif

G_BEGIN_DECLS

/**
 * SECTION:cogl-context
 * @short_description: The top level application context.
 *
 * A CoglContext is the topmost sandbox of Cogl state for an
 * application or toolkit. Its main purpose is to bind together the
 * key state objects at any one time; with the most significant being
 * the current framebuffer being drawn too (See #CoglFramebuffer for
 * more details) and the current GPU pipeline configuration (See
 * #CoglPipeline for more details).
 */

typedef struct _CoglContext	      CoglContext;

#define COGL_CONTEXT(OBJECT) ((CoglContext *)OBJECT)

#define cogl_context_new cogl_context_new_EXP

CoglContext *
cogl_context_new (CoglDisplay *display,
                  GError **error);

#define cogl_set_default_context cogl_set_default_context_EXP
void
cogl_set_default_context (CoglContext *context);

#ifdef COGL_HAS_EGL_SUPPORT
#define cogl_context_egl_get_egl_display cogl_context_egl_get_egl_display_EXP
EGLDisplay
cogl_context_egl_get_egl_display (CoglContext *context);
#endif

G_END_DECLS

#endif /* __COGL_CONTEXT_H__ */

