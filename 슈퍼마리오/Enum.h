#pragma once

namespace OBJID
{
	enum ID {
		MAP, PLAYER, MONSTER, BULLET, ITEM, END
	};
}

namespace PLAYER
{
	enum STATE { 
		PS_IDLE			// �ȴ� ����, ���� ����
		, PS_BIG		// ������ �Ծ ū ����
		, PS_ANGRY		// ������ �Ծ �Ҳ� ��� ����
		, PS_POWERFUL	// ���� ����
		, PS_RUNNING	// �޸��� ����
		, PS_END
	};
}