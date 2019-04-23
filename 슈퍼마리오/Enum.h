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
		PS_IDLE			// �ȴ� ����, ���� ����
		, PS_ANGRY		// ������ �Ծ �Ҳ� ��� ����
		, PS_POWERFUL	// ���� ����
		, PS_RUNNING	// �޸��� ����
		, PS_END
	};
}