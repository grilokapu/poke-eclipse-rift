EventScript_PictureBookShelf::
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end

EventScript_BookShelf::
	msgbox Text_BookShelf, MSGBOX_SIGN
	end

EventScript_PokemonCenterBookShelf::
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end

EventScript_Vase::
	msgbox Text_Vase, MSGBOX_SIGN
	end

EventScript_EmptyTrashCan::
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end

EventScript_ShopShelf::
	goto_if_eq VAR_LANGUAGE, PT, EventScript_ShopShelfPt
	goto_if_eq VAR_LANGUAGE, ES, EventScript_ShopShelfEs
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end

EventScript_ShopShelfPt:
	msgbox Text_ShopShelfPt, MSGBOX_SIGN
	end

EventScript_ShopShelfEs:
	msgbox Text_ShopShelfEs, MSGBOX_SIGN
	end

EventScript_Blueprint::
	msgbox Text_Blueprint, MSGBOX_SIGN
	end
