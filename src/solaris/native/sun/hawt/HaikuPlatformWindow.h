/*
 * Copyright (c) 2012, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */
#ifndef HAIKU_PLATFORM_WINDOW_H
#define	HAIKU_PLATFORM_WINDOW_H

#include <View.h>
#include <Window.h>

#include "ContentView.h"
#include "Drawable.h"
#include "Utilities.h"

class PlatformWindow : public BWindow {
public:
							PlatformWindow(jobject platformWindow,
								bool simple);

			Drawable*		GetDrawable();
			void			SetState(int state);
			void			Dispose(JNIEnv* env);
			void			Focus();

	virtual	void			FrameMoved(BPoint origin);
	virtual	void			FrameResized(float width, float height);
	virtual	void			Minimize(bool minimize);
	virtual	bool			QuitRequested();
	virtual	void			WindowActivated(bool active);
	virtual	void			Zoom(BPoint origin, float width, float height);
private:
			ContentView		fView;
			bool			fMaximized;
			jobject			fPlatformWindow;
};

#endif	/* HAIKU_PLATFORM_WINDOW_H */
