#pragma once

/*
 * The following enum is not enum class, to be able to convert its values implicitly to int
 * If you use enum class, then you have to cast it explicitly to int: (int) Screen::Width
 */

namespace Screen
{

enum
{
	Width = 600,
	Height = 600,
};

}
