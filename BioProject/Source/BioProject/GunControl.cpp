// Fill out your copyright notice in the Description page of Project Settings.


#include "GunControl.h"

// �R���X�g���N�^
AGunControl::AGunControl()
	: m_gunData(FGunData::NoneData())
{
}

// ����
void AGunControl::Shot()
{

}

// �����[�h����
void AGunControl::Reload(int& _ammoStock)
{
	// �e�򐔂�0�ȉ��̏ꍇ�͏������Ȃ�
	if (_ammoStock <= 0)
		return;

	// ���ɒe����[����Ă���ꍇ�͏������Ȃ�
	if (m_gunData.ammoStock >= m_gunData.ammoStockMax)
		return;

	// �������Ă���e�򂩂烊���[�h��������
	_ammoStock -= m_gunData.ammoStockMax - m_gunData.ammoStock;

	// �e�򂪑��肽�ꍇ
	if (_ammoStock >= 0)
	{
		// �ő�ʂ܂ő��₷
		m_gunData.ammoStock = m_gunData.ammoStockMax;
	}
	// �e�򂪑���Ȃ������ꍇ
	else
	{
		// �ő�ʂ��瑫��Ȃ���������������������
		m_gunData.ammoStock = m_gunData.ammoStockMax + _ammoStock;

		// �e�򐔂�0�����ɂȂ�Ȃ��悤�⊮
		_ammoStock = 0;
	}
}