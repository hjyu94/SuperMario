#pragma once

namespace OBJID
{
	enum ID {
		MONSTER, BLOCK, PLAYER, BULLET, MONSTER_BULLET, ITEM, END
	};
}

namespace PLAYER
{
	enum STATE { 
		PS_IDLE			// 걷는 상태, 작은 상태
		, PS_ANGRY		// 아이템 먹어서 불꽃 쏘는 상태
		, PS_POWERFUL	// 무적 상태
		, PS_RUNNING	// 달리는 중임
		, PS_END
	};
}