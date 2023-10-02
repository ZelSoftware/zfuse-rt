/*
* Zel Software, SP
* Last modified: 10/01/2023
* This file is part of zfuse, licensed under the MIT License (MIT).
* See the LICENSE file in the project root for license information.
*/

#include <cstddef>
#include <string_view>

namespace zfuse
{
	enum StatusCode : int
	{
		StatusCode_Ok = 0, // No error
		StatusCode_InvalidArgument = 1, // Invalid argument
		StatusCode_InternalError = 2, // Internal error
		StatusCode_Unimplemented = 3, // Functionality not implemented
		StatusCode_NotFound = 4, // Resource not found
		StatusCode_AccessDenied = 5, // Access denied
		StatusCode_Timeout = 6, // Operation timed out
		StatusCode_AlreadyExists = 7, // Resource already exists
		StatusCode_OutOfMemory = 8, // Out of memory
		StatusCode_Busy = 9, // Resource is busyw
		StatusCode_NotInitialized = 10, // Resource not initialized
		StatusCode_EndOfFile = 11, // End of file reached
		StatusCode_BadFormat = 12, // Data format is not correct
		StatusCode_Aborted = 13, // Operation was aborted
		StatusCode_Unknown = 14 // Unknown error

	}; // enum StatusCode

	class Status final
	{
	public: // Constructor & Destructor
		Status() noexcept
			: m_Code(StatusCode_Ok), m_Message("")
		{
		}

		Status(StatusCode code, std::string_view message) noexcept
			: m_Code(code), m_Message(message)
		{
		}

		Status(const Status& other) noexcept
			: m_Code(other.m_Code), m_Message(other.m_Message)
		{
		}

		Status(Status&& other) noexcept
			: m_Code(other.m_Code), m_Message(other.m_Message)
		{
		}

		~Status() = default;

	public: // Operators
		Status& operator=(const Status& other) noexcept
		{
			this->Copy(other);
			return *this;
		}

		Status& operator=(Status&& other) noexcept
		{
			this->Copy(other);
			return *this;
		}

		bool operator==(const Status& other) const noexcept
		{
			return m_Code == other.m_Code;
		}

		bool operator!=(const Status& other) const noexcept
		{
			return m_Code != other.m_Code;
		}

		bool operator==(StatusCode code) const noexcept
		{
			return m_Code == code;
		}

		bool operator!=(StatusCode code) const noexcept
		{
			return m_Code != code;
		}

		operator bool() const noexcept
		{
			return m_Code == StatusCode_Ok;
		}

	public: // Methods
		StatusCode Code() const noexcept
		{
			return m_Code;
		}

		std::string_view Message() const noexcept
		{
			return m_Message;
		}

		bool IsOk() const noexcept
		{
			return m_Code == StatusCode_Ok;
		}

	private: // Methods
		void Copy(const Status& other) noexcept
		{
			m_Code = other.m_Code;
			m_Message = other.m_Message;
		}

	private: // Member Variables
		StatusCode m_Code;
		std::string_view m_Message;

	}; // class Status

	inline namespace status_helpers
	{
		Status OkStatus();
		Status InvalidArgumentStatus(std::string_view message);
		Status InternalErrorStatus(std::string_view message);
		Status UnimplementedStatus(std::string_view message);
		Status NotFoundStatus(std::string_view message);
		Status AccessDeniedStatus(std::string_view message);
		Status TimeoutStatus(std::string_view message);
		Status AlreadyExistsStatus(std::string_view message);
		Status OutOfMemoryStatus(std::string_view message);
		Status BusyStatus(std::string_view message);
		Status NotInitializedStatus(std::string_view message);
		Status EndOfFileStatus(std::string_view message);
		Status BadFormatStatus(std::string_view message);
		Status AbortedStatus(std::string_view message);
		Status UnknownStatus(std::string_view message);

	} // namespace status_helpers

} // namespace zfuse