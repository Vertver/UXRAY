///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *	OPCODE - Optimized Collision Detection
 *	Copyright (C) 2001 Pierre Terdiman
 *	Homepage: http://www.codercorner.com/Opcode.htm
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains base volume collider class.
 *	\file		OPC_VolumeCollider.h
 *	\author		Pierre Terdiman
 *	\date		June, 2, 2001
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef __OPC_VOLUMECOLLIDER_H__
#define __OPC_VOLUMECOLLIDER_H__

struct OPCODE_API VolumeCache {
    VolumeCache() {}

    Container TouchedPrimitives; //!< Indices of touched primitives
};

class OPCODE_API VolumeCollider : public Collider {
public:
    // Constructor / Destructor
    VolumeCollider();
    virtual ~VolumeCollider() = 0;

    // Collision report

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Gets the number of touched primitives after a collision query.
     *	\see		GetContactStatus()
     *	\see		GetTouchedPrimitives()
     *	\return		the number of touched faces
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ udword GetNbTouchedPrimitives() const {
        return mTouchedPrimitives ? mTouchedPrimitives->GetNbEntries() : 0;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Gets the list of touched primitives after a collision query.
     *	\see		GetContactStatus()
     *	\see		GetNbTouchedPrimitives()
     *	\return		the list of touched primitives (primitive indices)
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ udword* GetTouchedPrimitives() const {
        return mTouchedPrimitives ? mTouchedPrimitives->GetEntries() : null;
    }

    // Stats

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Stats: gets the number of Volume-BV overlap tests after a collision query.
     *	\see		GetNbVolumePrimTests()
     *	\return		the number of Volume-BV tests performed during last query
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ udword GetNbVolumeBVTests() const { return mNbVolumeBVTests; }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Stats: gets the number of Volume-Triangle overlap tests after a collision query.
     *	\see		GetNbVolumeBVTests()
     *	\return		the number of Volume-Triangle tests performed during last query
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ udword GetNbVolumePrimTests() const { return mNbVolumePrimTests; }

// Settings

#ifdef OPC_USE_CALLBACKS
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Callback control: a method to setup object callback. Must provide triangle-vertices for a
     *given triangle index. \param		callback	[in] user-defined callback \param
     *user_data	[in] user-defined data
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ void SetCallback(OPC_CALLBACK callback, udword user_data) {
        mObjCallback = callback;
        mUserData = user_data;
    }
#else
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Pointers control: a method to setup object pointers. Must provide access to faces and
     *vertices for a given object. \param		faces	[in] pointer to faces \param
     *verts	[in] pointer to vertices
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inline_ void SetPointers(const IndexedTriangle* faces, const Point* verts) {
        mFaces = faces;
        mVerts = verts;
    }
#endif
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Validates current settings. You should call this method after all the settings / callbacks
     *have been defined for a collider. \return		null if everything is ok, else a
     *string describing the problem
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    override(Collider) const char* ValidateSettings();

protected:
    // Touched primitives
    Container* mTouchedPrimitives; //!< List of touched primitives
#ifdef OPC_USE_CALLBACKS
    // User callback
    udword mUserData;          //!< User-defined data sent to callback
    OPC_CALLBACK mObjCallback; //!< Object callback
#else
    // User pointers
    const IndexedTriangle* mFaces; //!< User-defined faces
    const Point* mVerts;           //!< User-defined vertices
#endif
    // Dequantization coeffs
    Point mCenterCoeff;
    Point mExtentsCoeff;
    // Stats
    udword mNbVolumeBVTests;   //!< Number of Volume-BV tests
    udword mNbVolumePrimTests; //!< Number of Volume-Primitive tests
                               // Internal methods
    void _Dump(const AABBCollisionNode* node);
    void _Dump(const AABBNoLeafNode* node);
    void _Dump(const AABBQuantizedNode* node);
    void _Dump(const AABBQuantizedNoLeafNode* node);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     *	Initializes a query
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    override(Collider) inline_ void InitQueryEx() {
        // Reset stats & contact status
        mNbVolumeBVTests = 0;
        mNbVolumePrimTests = 0;
        Collider::InitQueryEx();
    }
};

#endif // __OPC_VOLUMECOLLIDER_H__
