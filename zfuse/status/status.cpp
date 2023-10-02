#include "status.h"

zfuse::Status zfuse::status_helpers::OkStatus()
{
	return Status();
}

zfuse::Status zfuse::status_helpers::InvalidArgumentStatus(std::string_view message)
{
	return Status(StatusCode_InvalidArgument, message);
}

zfuse::Status zfuse::status_helpers::InternalErrorStatus(std::string_view message)
{
	return Status(StatusCode_InternalError, message);
}

zfuse::Status zfuse::status_helpers::UnimplementedStatus(std::string_view message)
{
	return Status(StatusCode_Unimplemented, message);
}

zfuse::Status zfuse::status_helpers::NotFoundStatus(std::string_view message)
{
	return Status(StatusCode_NotFound, message);
}

zfuse::Status zfuse::status_helpers::AccessDeniedStatus(std::string_view message)
{
	return Status(StatusCode_AccessDenied, message);
}

zfuse::Status zfuse::status_helpers::TimeoutStatus(std::string_view message)
{
	return Status(StatusCode_Timeout, message);
}

zfuse::Status zfuse::status_helpers::AlreadyExistsStatus(std::string_view message)
{
	return Status(StatusCode_AlreadyExists, message);
}

zfuse::Status zfuse::status_helpers::OutOfMemoryStatus(std::string_view message)
{
	return Status(StatusCode_OutOfMemory, message);
}

zfuse::Status zfuse::status_helpers::BusyStatus(std::string_view message)
{
	return Status(StatusCode_Busy, message);
}

zfuse::Status zfuse::status_helpers::NotInitializedStatus(std::string_view message)
{
	return Status(StatusCode_NotInitialized, message);
}

zfuse::Status zfuse::status_helpers::EndOfFileStatus(std::string_view message)
{
	return Status(StatusCode_EndOfFile, message);
}

zfuse::Status zfuse::status_helpers::BadFormatStatus(std::string_view message)
{
	return Status(StatusCode_BadFormat, message);
}

zfuse::Status zfuse::status_helpers::AbortedStatus(std::string_view message)
{
	return Status(StatusCode_Aborted, message);
}

zfuse::Status zfuse::status_helpers::UnknownStatus(std::string_view message)
{
	return Status(StatusCode_Unknown, message);
}
