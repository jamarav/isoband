#ifndef LABELS_H
#define LABELS_H

#include <Rcpp.h>
using namespace Rcpp;

#include "polygon.h"

enum segment_crop_type {
  none,         // segment wasn't cropped
  complete,     // entire segment is gone
  at_beginning,    // beginning of segment is gone
  at_end,          // end of segment is gone
  in_middle        // middle of segment is gone
};

// crops the line segment running from p1 to p2 to a unit box
segment_crop_type crop_to_unit_box(const point &p1, const point &p2, point &crop1, point &crop2);


// a class that can transform coordinates to and from a new coordinate system relative to a unit box
class unitbox_transformer {
protected:
  double m00, m01, m10, m11; // transformation matrix
  double mi00, mi01, mi10, mi11; // inverse transformation matrix
  point base;

public:
  unitbox_transformer(const point &low_left, const point &low_right, const point &up_left) :
    base(low_left)
  {
    double x0 = low_right.x - low_left.x;
    double y0 = low_right.y - low_left.y;
    double x1 = up_left.x - low_left.x;
    double y1 = up_left.y - low_left.y;

    if ((x0 == 0 && y0 == 0) || (x1 == 0 && y1 == 0)) {
      stop("singular transformation due to invalid box extent");
    }

    m00 = x0/(x0*x0 + y0*y0);
    m01 = y0/(x0*x0 + y0*y0);
    m10 = x1/(x1*x1 + y1*y1);
    m11 = y1/(x1*x1 + y1*y1);

    double det = m01*m10 - m11*m00;

    if (det == 0) {
      stop("singular transformation due to invalid box extent");
    }

    mi00 = -m11/det;
    mi01 = m01/det;
    mi10 = m10/det;
    mi11 = -m00/det;

    /*
    cout << "base: " << base << endl;
    cout << "M:\t" << m00 << "\t" << m01 << endl;
    cout << "\t" << m10 << "\t" << m11 << endl;
    cout << "Minv:\t" << mi00 << "\t" << mi01 << endl;
    cout << "\t" << mi10 << "\t" << mi11 << endl;
    */
  }

  point transform(const point &p) {
    double x = p.x - base.x;
    double y = p.y - base.y;
    return point(m00*x + m01*y, m10*x + m11*y);
  }

  point inv_transform(const point &p) {
    double x = mi00*p.x + mi01*p.y;
    double y = mi10*p.x + mi11*p.y;
    return point(x + base.x, y + base.y);
  }

};

#endif // LABELS_H
