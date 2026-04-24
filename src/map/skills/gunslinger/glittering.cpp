// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#include "glittering.hpp"

#include "map/clif.hpp"
#include "map/pc.hpp"

SkillGlittering::SkillGlittering() : SkillImpl(GS_GLITTERING) {
}

void SkillGlittering::castendNoDamageId(block_list *src, block_list *target, uint16 skill_lv, t_tick tick, int32 &flag) const {
	map_session_data *sd = BL_CAST(BL_PC, src);

	if (sd) {
		clif_skill_nodamage(src, *target, getSkillId(), skill_lv);
		for (int32 i = 0; i < skill_lv; i++)
			pc_addspiritball(sd, skill_get_time(getSkillId(), skill_lv), 10);
	}
}
