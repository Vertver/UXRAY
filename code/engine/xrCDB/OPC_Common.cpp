///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	OPCODE - Optimized Collision Detection
 *	Copyright (C) 2001 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Opcode.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains common classes & defs used in OPCODE.
 *	\file		OPC_Common.cpp
 *	\author		Pierre Terdiman
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This structure holds 3 vertex-pointers. It's mainly used by collision callbacks so that the
 *app doesn't have to return 3 vertices to Opcode (36 bytes) but only 3 pointers (12 bytes). It
 *seems better but I never profiled the alternative.
 *
 *	\class		VertexPointers
 *	\author		Pierre Terdiman
 *	\version	1.2
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	An AABB dedicated to collision detection.
 *	We don't use the generic AABB class included in ICE, since it can be a Min/Max or a
 *Center/Extents one (depends on compilation flags). Since the Center/Extents model is more
 *efficient in collision detection, it was worth using an extra special class.
 *
 *	\class		CollisionAABB
 *	\author		Pierre Terdiman
 *	\version	1.2
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	A quantized AABB.
 *	Center/Extent model, using 16-bits integers.
 *
 *	\class		QuantizedAABB
 *	\author		Pierre Terdiman
 *	\version	1.2
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This class describes a face hit by a ray or segment.
 *	This is a particular class dedicated to stabbing queries.
 *
 *	\class		CollisionFace
 *	\author		Pierre Terdiman
 *	\version	1.2
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	This class is a dedicated collection of CollisionFace.
 *
 *	\class		CollisionFaces
 *	\author		Pierre Terdiman
 *	\version	1.2
 *	\date		March, 20, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Precompiled Header
#include "stdafx.h"
#pragma hdrstop

using namespace Opcode;
