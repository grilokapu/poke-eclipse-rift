OBJEVENTGFXDIR := graphics/object_events/pics
FLDEFFGFXDIR := graphics/field_effects/pics

# Custom 32x32 field-effect animations. These need an explicit metatile
# layout so each horizontal 32x32 frame is emitted as 16 consecutive tiles.
$(FLDEFFGFXDIR)/magnect_portal.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(FLDEFFGFXDIR)/stoneedge.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4

# Three horizontal 16x32 frames used by the permanent NPC quest marker.
$(FLDEFFGFXDIR)/quest_exclamation_mark.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(FLDEFFGFXDIR)/cavesymbol.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(FLDEFFGFXDIR)/player_bright_m.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(FLDEFFGFXDIR)/player_bright_f.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 4 -mheight 4

# Both player-bright sheets use the same palette, stored in the male PNG.
$(FLDEFFGFXDIR)/player_bright_m.gbapal: %.gbapal: %.png
	$(GFX) $< $@

$(OBJEVENTGFXDIR)/people/brendan/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/brendan/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/may/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/may/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_may/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_may/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4
