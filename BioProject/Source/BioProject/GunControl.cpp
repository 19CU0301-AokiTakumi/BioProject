// Fill out your copyright notice in the Description page of Project Settings.


#include "GunControl.h"

AGunControl::AGunControl()
	: m_gunData(FGunData::NoneData())
{

}

void AGunControl::Shot()
{

}

void AGunControl::Reload(int _playerHaveAmmo)
{
	/*if (_playerHaveAmmo <= 0)
		return;

	if (m_gunData.ammoStock >= m_gunData.ammoStockMax)
		return;

	m_iStockAmmo -= 10 - m_iGunAmmoCount;

	if (m_iStockAmmo >= 0)
	{
		m_iGunAmmoCount += 10 - m_iGunAmmoCount;
	}
	else
	{
		m_iGunAmmoCount = 10 + m_iStockAmmo;
		m_iStockAmmo = 0;
	}*/
}