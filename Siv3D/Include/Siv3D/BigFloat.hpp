﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2016 Ryo Suzuki
//	Copyright (C) 2016 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <memory>
# include <iostream>
# include "Fwd.hpp"
# include "BigInt.hpp"
# include "String.hpp"
# include "Format.hpp"

namespace s3d
{
	class BigFloat
	{
	private:

		struct CBigFloat;
		std::unique_ptr<CBigFloat> pImpl;
	
		friend BigFloat operator /(int64 a, const BigFloat& b);
		friend BigFloat operator /(uint64 a, const BigFloat& b);
		friend BigFloat operator /(long double a, const BigFloat& b);

	public:

		BigFloat() : BigFloat(0.0) {}
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat(Integer i) : BigFloat(static_cast<int64>(i)) {}
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat(Integer i) : BigFloat(static_cast<uint64>(i)) {}
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat(Float f) : BigFloat(static_cast<long double>(f)) {}
		BigFloat(int64 f);
		BigFloat(uint64 f);
		BigFloat(long double f);
		BigFloat(const BigInt& number);
		explicit BigFloat(const char* number);
		explicit BigFloat(const wchar* number);
		explicit BigFloat(const std::string& number);
		explicit BigFloat(const std::wstring& number);
		explicit BigFloat(const String& number) : BigFloat(number.str()) {}
		BigFloat(const BigFloat& other);
		BigFloat(BigFloat&& other);
		~BigFloat();

		BigFloat& assign(int64 i);
		BigFloat& assign(uint64 i);
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& assign(Integer i) { return assign(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& assign(Integer i) { return assign(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& assign(Float f) { return assign(static_cast<long double>(f)); }
		BigFloat& assign(long double f);
		BigFloat& assign(const BigInt& number);
		BigFloat& assign(const char* number);
		BigFloat& assign(const wchar* number);
		BigFloat& assign(const std::string& number);
		BigFloat& assign(const std::wstring& number);
		BigFloat& assign(const String& number) { return assign(number.str()); }
		BigFloat& assign(const BigFloat& other);
		BigFloat& assign(BigFloat&& other);

		BigFloat& operator =(int64 i) { return assign(i); }
		BigFloat& operator =(uint64 i) { return assign(i); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator =(Integer i) { return assign(i); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator =(Integer i) { return assign(i); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator =(Float f) { return assign(static_cast<long double>(f)); }
		BigFloat& operator =(long double f) { return assign(f); }
		BigFloat& operator =(const BigInt& number) { return assign(number); }
		BigFloat& operator =(const char* number) { return assign(number); }
		BigFloat& operator =(const wchar* number) { return assign(number); }
		BigFloat& operator =(const std::string& number) { return assign(number); }
		BigFloat& operator =(const std::wstring& number) { return assign(number); }
		BigFloat& operator =(const String& number) { return assign(number); }
		BigFloat& operator =(const BigFloat& other) { return assign(other); }
		BigFloat& operator =(BigFloat&& other) { return assign(std::move(other)); }

		const BigFloat& operator +() const { return *this; }
		BigFloat& operator ++();
		BigFloat operator ++(int);
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator +(Integer i) const { return operator +(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator +(Integer i) const { return operator +(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator +(Float f) { return operator +(static_cast<long double>(f)); }	
		BigFloat operator +(int64 i) const;
		BigFloat operator +(uint64 i) const;
		BigFloat operator +(long double f) const;
		BigFloat operator +(const BigInt& number) const;
		BigFloat operator +(const BigFloat& number) const;
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator +=(Integer i) { return operator +=(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator +=(Integer i) { return operator +=(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator +=(Float f) { return operator +=(static_cast<long double>(f)); }
		BigFloat& operator +=(int64 i);
		BigFloat& operator +=(uint64 i);
		BigFloat& operator +=(long double f);
		BigFloat& operator +=(const BigInt& number);
		BigFloat& operator +=(const BigFloat& number);

		const BigFloat& operator -() const { return *this; }
		BigFloat& operator --();
		BigFloat operator --(int);
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator -(Integer i) const { return operator -(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator -(Integer i) const { return operator -(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator -(Float f) { return operator -(static_cast<long double>(f)); }
		BigFloat operator -(int64 i) const;
		BigFloat operator -(uint64 i) const;
		BigFloat operator -(long double f) const;
		BigFloat operator -(const BigInt& number) const;
		BigFloat operator -(const BigFloat& number) const;
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator -=(Integer i) { return operator -=(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator -=(Integer i) { return operator -=(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator -=(Float f) { return operator -=(static_cast<long double>(f)); }
		BigFloat& operator -=(int64 i);
		BigFloat& operator -=(uint64 i);
		BigFloat& operator -=(long double f);
		BigFloat& operator -=(const BigInt& number);
		BigFloat& operator -=(const BigFloat& number);

		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator *(Integer i) const { return operator *(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator *(Integer i) const { return operator *(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator *(Float f) { return operator *(static_cast<long double>(f)); }
		BigFloat operator *(int64 i) const;
		BigFloat operator *(uint64 i) const;
		BigFloat operator *(long double f) const;
		BigFloat operator *(const BigInt& number) const;
		BigFloat operator *(const BigFloat& number) const;
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator *=(Integer i) { return operator *=(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator *=(Integer i) { return operator *=(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator *=(Float f) { return operator *=(static_cast<long double>(f)); }
		BigFloat& operator *=(int64 i);
		BigFloat& operator *=(uint64 i);
		BigFloat& operator *=(long double f);
		BigFloat& operator *=(const BigInt& number);
		BigFloat& operator *=(const BigFloat& number);

		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator /(Integer i) const { return operator /(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat operator /(Integer i) const { return operator /(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator /(Float f) { return operator /(static_cast<long double>(f)); }
		BigFloat operator /(int64 i) const;
		BigFloat operator /(uint64 i) const;
		BigFloat operator /(long double f) const;
		BigFloat operator /(const BigInt& number) const;
		BigFloat operator /(const BigFloat& number) const;
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator /=(Integer i) { return operator /=(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		BigFloat& operator /=(Integer i) { return operator /=(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<(std::is_floating_point<Float>::value)>* = nullptr>
		BigFloat& operator /=(Float f) { return operator /=(static_cast<long double>(f)); }
		BigFloat& operator /=(int64 i);
		BigFloat& operator /=(uint64 i);
		BigFloat& operator /=(long double f);
		BigFloat& operator /=(const BigInt& number);
		BigFloat& operator /=(const BigFloat& number);

		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
		int32 compare(Integer i) const { return compare(static_cast<int64>(i)); }
		template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
		int32 compare(Integer i) const { return compare(static_cast<uint64>(i)); }
		template <class Float, std::enable_if_t<std::is_floating_point<Float>::value>* = nullptr>
		int32 compare(Float f) const { return compare(static_cast<long double>(f)); }
		int32 compare(int64 i) const;
		int32 compare(uint64 i) const;
		int32 compare(long double f) const;
		int32 compare(const BigInt& number) const;
		int32 compare(const BigFloat& number) const;

		explicit operator bool() const;
		bool isZero() const;
		int32 sign() const;
		BigFloat abs() const;

		float asFloat() const;
		double asDouble() const;
		long double asLongDouble() const;

		std::string stdStr() const;
		
		String str() const
		{
			const std::string t = stdStr();
			return String(t.begin(), t.end());
		}

		void swap(BigFloat& other) noexcept;
	};

	template <class Type, std::enable_if_t<std::is_arithmetic<Type>::value>* = nullptr>
	inline BigFloat operator +(const Type& a, const BigFloat& b)
	{
		return b + a;
	}

	template <class Type, std::enable_if_t<std::is_arithmetic<Type>::value>* = nullptr>
	inline BigFloat operator -(const Type& a, const BigFloat& b)
	{
		return -b + a;
	}

	template <class Type, std::enable_if_t<std::is_arithmetic<Type>::value>* = nullptr>
	inline BigFloat operator *(const Type& a, const BigFloat& b)
	{
		return b * a;
	}

	template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && std::is_signed<Integer>::value)>* = nullptr>
	inline BigFloat operator /(Integer a, const BigFloat& b)
	{
		return static_cast<int64>(a) / b;
	}

	template <class Integer, std::enable_if_t<(std::is_integral<Integer>::value && !std::is_signed<Integer>::value)>* = nullptr>
	inline BigFloat operator /(Integer a, const BigFloat& b)
	{
		return static_cast<uint64>(a) / b;
	}

	template <class Float, std::enable_if_t<std::is_floating_point<Float>::value>* = nullptr>
	inline BigFloat operator /(Float a, const BigFloat& b)
	{
		return static_cast<long double>(a) / b;
	}

	BigFloat operator /(int64 a, const BigFloat& b);
	BigFloat operator /(uint64 a, const BigFloat& b);
	BigFloat operator /(long double a, const BigFloat& b);

	namespace literals
	{
		inline namespace bigfloat_literals
		{
			inline BigFloat operator ""_bigF(unsigned long long int i)
			{
				return BigFloat(i);
			}

			inline BigFloat operator ""_bigF(const char* number, size_t)
			{
				return BigFloat(number);
			}

			inline BigFloat operator ""_bigF(const wchar* number, size_t)
			{
				return BigFloat(number);
			}
		}
	}

	inline bool operator ==(const BigFloat& a, const BigFloat& b)
	{
		return a.compare(b) == 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator ==(const BigFloat& a, Number b)
	{
		return a.compare(b) == 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator ==(Number a, const BigFloat& b)
	{
		return b.compare(a) == 0;
	}

	inline bool operator !=(const BigFloat& a, const BigFloat& b)
	{
		return a.compare(b) != 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator !=(const BigFloat& a, Number b)
	{
		return a.compare(b) != 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator !=(Number a, const BigFloat& b)
	{
		return b.compare(a) != 0;
	}

	inline bool operator <(const BigFloat& a, const BigFloat& b)
	{
		return a.compare(b) < 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator <(const BigFloat& a, Number b)
	{
		return a.compare(b) < 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator <(Number a, const BigFloat& b)
	{
		return b.compare(a) < 0;
	}

	inline bool operator <=(const BigFloat& a, const BigFloat& b)
	{
		return a.compare(b) <= 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator <=(const BigFloat& a, Number b)
	{
		return a.compare(b) <= 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator <=(Number a, const BigFloat& b)
	{
		return b.compare(a) <= 0;
	}

	inline bool operator >(const BigFloat& a, const BigFloat& b)
	{
		return a.compare(b) > 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator >(const BigFloat& a, Number b)
	{
		return a.compare(b) > 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator >(Number a, const BigFloat& b)
	{
		return b.compare(a) > 0;
	}

	inline bool operator >=(const BigFloat& a, const BigFloat& b)
	{
		return a.compare(b) >= 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator >=(const BigFloat& a, Number b)
	{
		return a.compare(b) >= 0;
	}

	template <class Number, std::enable_if_t<std::is_arithmetic<Number>::value>* = nullptr>
	inline bool operator >=(Number a, const BigFloat& b)
	{
		return b.compare(a) >= 0;
	}

	inline std::ostream& operator <<(std::ostream& os, const BigFloat& f)
	{
		return os << f.stdStr();
	}

	inline std::wostream& operator <<(std::wostream& os, const BigFloat& f)
	{
		return os << f.str();
	}

	inline std::istream& operator >> (std::istream& is, BigFloat& f)
	{
		std::string s;
		is >> s;
		f.assign(s);
		return is;
	}

	inline std::wistream& operator >> (std::wistream& is, BigFloat& f)
	{
		std::wstring s;
		is >> s;
		f.assign(s);
		return is;
	}

	inline void Formatter(FormatData& formatData, const BigFloat& f)
	{
		formatData.string.append(f.str());
	}
}

namespace std
{
	void inline swap(s3d::BigFloat& a, s3d::BigFloat& b) noexcept(noexcept(a.swap(b)))
	{
		a.swap(b);
	}
}