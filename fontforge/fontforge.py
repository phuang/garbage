# -*- coding: utf-8 -*-
import fontforge
import cairo
import gobject
import gtk
from math import sqrt


class CairoView(gtk.DrawingArea):
    __gsignals__ = { "expose-event" : "override" }
    def __init__(self):
        super(CairoView, self).__init__()
        self.set_size_request(400, 400)
        self.__glyph = None


    def do_expose_event(self, event):
        cr = self.window.cairo_create()

        cr.rectangle(event.area.x, event.area.y, event.area.width, event.area.height)

        self.draw(cr, *self.window.get_size())

    def draw(self, cr, width, height):
        cr.set_source_rgb(0.5, 0.5, 0.5)
        cr.rectangle(0, 0, width, height)
        cr.fill()

class Point(object):
    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)
    def dist(self, p):
        s = sqrt((self.x - p.x) ** 2 + (self.y - p.y) ** 2)
        return s

class Line(object):
    def __init__(self, a, b, c):
        self.a = float(a)
        self.b = float(b)
        self.c = float(c)

    def dist(self, p):
        s = (self.a * p.x + self.b * p.y + self.c) / sqrt(self.a ** 2 + self.b ** 2)
        return abs(s)

class Line2(Line):
    def __init__(self, x0, y0, x1, y1):
        x0, y0, x1, y1 = float(x0), float(y0), float(x1), float(y1)
        a = (y0 - y1) / (x0 - x1)
        b = 1.0
        c = (x0 * y1 + x1 * y0 - 2 * x0 * y0) / (x0 - x1)
        super(Line2, self).__init__(a, b, c)

class GlyphView(CairoView):
    def __init__(self):
        super(GlyphView, self).__init__()
        self.__glyph = None

    def set_glyph(self, glyph):
        self.__glyph = glyph

    def draw_contour(self, cr, contour):
        points = []
        x0 = contour[0].x 
        y0 = contour[0].y
        cr.move_to(x0, y0)
        points.append((x0, y0, 0))
        i = 1
        nr = len(contour)
        while i < nr:
            if contour[i].on_curve:
                x1, y1 = contour[i].x, contour[i].y
                if abs(x0 - x1) < 5:
                    x1 = x0
                if abs(y0 - y1) < 5:
                    y1 = y0
                    
                cr.line_to(x1, y1)
                x0, y0 = x1, y1
                points.append((x0, y0, 0))
                i += 1
            else:
                fx, fy = contour[i].x, contour[i].y
                x1 = x0 + 2.0 / 3.0 * (fx - x0)
                y1 = y0 + 2.0 / 3.0 * (fy - y0)
                x3, y3 = (contour[i+1].x, contour[i+1].y) if i < nr - 1 \
                    else (contour[0].x, contour[0].y)
                x2 = x3 + 2.0 / 3.0 * (fx - x3)
                y2 = y3 + 2.0 / 3.0 * (fy - y3)
                
                if abs(x0 - x3) < 5:
                    x3 = x0
                    cr.line_to (x3, y3)
                    points.append((x3, y3, 0))
                elif abs(y0 - y3) < 5:
                    y3 = y0
                    cr.line_to (x3, y3)
                    points.append((x3, y3, 0))
                else:
                    p1 = Point(x1, y1)
                    p2 = Point(x2, y2)
                    line = Line2(x0, y0, x3, y3)
                    d = p1.dist(p2)
                    if d / line.dist(p1) > 300 and d / line.dist(p1) > 300:
                        print "strip"
                        cr.line_to (x3, y3)
                        points.append((x3, y3, 0))
                    else:
                        cr.curve_to(x1, y1, x2, y2, x3, y3)
                        points.append((x1, y1, 1))
                        points.append((x2, y2, 2))
                        points.append((x3, y3, 0))
                x0 = x3 
                y0 = y3
                i += 2
        if i == nr:
            cr.close_path()
        cr.set_source_rgb(0, 0, 0)
        cr.stroke()

        for x, y, f in points:
            if 0 == f:
                cr.set_source_rgb(0.5, 0, 0)
            elif 1 == f:
                cr.set_source_rgb(0, 0.5, 0)
            else:
                cr.set_source_rgb(0, 0, 0.5)
            cr.rectangle(x - 4, y - 4, 8, 8)
            cr.fill()

    def draw(self, cr, width, height):
        if self.__glyph == None:
            return
        cr.save()
        cr.scale(width / 3024., height / -3024.)
        cr.translate(0, -2500)
        # cr.rotate(-3.1415926)
        layer = self.__glyph.layers[1]
        for contour in layer:
            self.draw_contour(cr, contour)
        cr.restore()

def process_contour(contour):
    points = []
    x0 = contour[0].x 
    y0 = contour[0].y
    points.append((x0, y0, 0))
    i = 1
    nr = len(contour)
    while i < nr:
        if contour[i].on_curve:
            # line
            x1, y1 = contour[i].x, contour[i].y
            if abs(x0 - x1) < 8:
                x1 = x0
            if abs(y0 - y1) < 8:
                y1 = y0
            points.append((x1, y1, 1))
            x0, y0 = x1, y1
            i += 1
        else:
            # curve
            fx, fy = contour[i].x, contour[i].y
            x1 = x0 + 2.0 / 3.0 * (fx - x0)
            y1 = y0 + 2.0 / 3.0 * (fy - y0)
            x3, y3 = (contour[i+1].x, contour[i+1].y) if i < nr - 1 \
                else (contour[0].x, contour[0].y)
            x2 = x3 + 2.0 / 3.0 * (fx - x3)
            y2 = y3 + 2.0 / 3.0 * (fy - y3)
            
            if abs(x0 - x3) < 8:
                x3 = x0
                points.append((x3, y3, 1))
            elif abs(y0 - y3) < 8:
                y3 = y0
                points.append((x3, y3, 1))
            else:
                # p1 = Point(x1, y1)
                # p2 = Point(x2, y2)
                # line = Line2(x0, y0, x3, y3)
                # d = p1.dist(p2)
                # if line.dist(p1) / d  > 0.001 and line.dist(p1) / d > 0.001:
                #     points.append((x3, y3, 1))
                # else:
                #     points.append((fx, fy, 0))
                #     points.append((x3, y3, 1))
                points.append((fx, fy, 0))
                points.append((x3, y3, 1))
            y0 = y3
            i += 2
    return points

def process_glyph(glyph):
    layers = []
    for n in glyph.layers:
        layers.append([process_contour(c) for c in glyph.layers[n]])
    return layers

def process_font(filename, n=-1, chars=None):
    font = fontforge.open(filename)
    if n <= 0:
        n = len(font) 
    for i, name in enumerate(font):
        if i >= n:
            break
        print "process  [%s - %d/%d]" % (name, i, n)
        glyph = font[name]
        glyph_new = process_glyph(glyph)
        pen = glyph.glyphPen(True)

        for layer in glyph_new:
            for c in layer:
                x0, y0, f = c[0]
                pen.moveTo((x0, y0))
                i = 1
                nr = len(c)
                while i < nr:
                    x1, y1, f1 = c[i]
                    if f1:
                        pen.lineTo((x1, y1))
                        i += 1
                    else:
                        x2, y2, f2 = c[i + 1]
                        pen.curveTo((x1, y1), (x2, y2))
                        i += 2
                pen.closePath()
        pen = None
    font.generate("new.ttf")

font_name = ""
font_file = "wqy-zenhei.ttc"
# font_file = "VL-Gothic-Regular.ttf"
# font_file = "msyh.ttf"

def main():
    process_font(font_file)
    return
    window = gtk.Window()
    view = GlyphView()
    view.set_glyph(font[ord(u"倪")])
    # view.set_glyph(font[ord(u"a")])
    # view.set_glyph(font[ord(u"h")])
    view.set_glyph(font[ord(u"o")])

    window.add(view)
    window.show_all()
    gtk.main()

if __name__ == "__main__":
    main()
