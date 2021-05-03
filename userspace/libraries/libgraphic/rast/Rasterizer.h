#pragma once

#include <libutils/Array.h>

#include <libgraphic/Bitmap.h>
#include <libgraphic/rast/EdgeList.h>
#include <libgraphic/rast/Paint.h>
#include <libgraphic/svg/Path.h>

namespace Graphic
{

class Rasterizer
{
private:
    static constexpr auto TOLERANCE = 0.25f;
    static constexpr auto MAX_DEPTH = 8;

    RefPtr<Bitmap> _bitmap;
    EdgeList _edges;
    Vector<Math::Edgef> _actives_edges;
    Optional<Math::Recti> _clip;
    Vector<uint16_t> _scanline;

    void clear();

    void flatten(const Path &path, const Math::Mat3x2f &transform);

    void flatten(const EdgeList &edges, const Math::Mat3x2f &transform);

    void rasterize(Paint &paint);

public:
    Rasterizer(RefPtr<Bitmap> bitmap);

    void set_clip(Math::Recti c);

    Math::Recti get_clip();

    void fill(const Path &path, const Math::Mat3x2f &transform, Paint paint);

    void fill(const EdgeList &edges, const Math::Mat3x2f &transform, Paint paint);
};

} // namespace Graphic
