#pragma once

#include "Primitive.h"

class SpherePrim : 
    public IPrimitive
{
public:
    SpherePrim();
    SpherePrim(Point3 center, float radius);
    virtual ~SpherePrim();

    //// IPrimitive Interface ////
    virtual bool intersect(Ray& r, HitInfo* pHitInfo);
    virtual bool intersectAABB(AABB box);
    virtual AABB getAABB() const;
    virtual std::list<Triangle*>* getNewTesselation(void);

private:
    Point3 m_Center;
    float   m_Radius;
};
